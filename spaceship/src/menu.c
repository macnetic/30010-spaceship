#include <stdint.h>
#include <stdio.h>
#include "lcd_driver.h"
#include "trig_lut.h"
#include "30010_io.h"
#include "charset.h"
#include "menu.h"
#define ESC 0x1B

//Screen navigation
void navigator(char buffer[]){
    switch(nextScreen){
        case 0:
            screen_main(buffer);
            break;
        case 2:
            screen_stageSelect(buffer);
            break;
        case 3:
            screen_help(buffer);
            break;
    }
}

//Different menu screens
void screen_main(char buffer[]){
    memset(buffer, 0x00, 512); //Clear screen

    lcdWriteString("(1) Start game",    buffer,0,0);
    lcdWriteString("(2) Select stage",  buffer,1,0);
    lcdWriteString("(3) Help",          buffer,2,0);
    lcdWriteString("(4) Let's dance!",  buffer,3,0);

    lcd_push_buffer((uint8_t*)buffer); //Update display

    read_chars(input,1); //Wait for input for next screen

    switch(input[0]){
        case '1':
            nextScreen = 1;
            break;
        case '2':
            nextScreen = 2;
            break;
        case '3':
            nextScreen = 3;
            break;
    }
}

void screen_help(char buffer[]){
    memset(buffer, 0x00, 512); //Clear screen

    lcdWriteString("(b)ack",buffer,3, 0);
    lcdWriteString("/4",    buffer,3,12);
    lcdWriteString("(n)ext",buffer,3,19);

    lcd_push_buffer((uint8_t*) buffer); //Update display
    uint8_t helpPage = 1;
    uint8_t nPages = 4;

    while(nextScreen == 3){
        memset(buffer, 0x00, 512/4 * 3); //Clear first three lines
        switch(helpPage){
            case 1:
                lcdWriteString("Use A and D to steer", buffer,0,0);
                lcdWriteString("W propels the spaceship", buffer,1,0);
                lcdWriteString("1",buffer,3,11);
                break;
            case 2:
                lcdWriteString("Press S to use the", buffer,0,0);
                lcdWriteString("spacebrake, slowing down", buffer,1,0);
                lcdWriteString("the ship", buffer,2,0);
                lcdWriteString("2",buffer,3,11);
                break;
            case 3:
                lcdWriteString("Space shoots bullets", buffer,0,0);
                lcdWriteString("Hit red enemies with", buffer,1,0);
                lcdWriteString("bullets to kill them", buffer,2,0);
                lcdWriteString("3",buffer,3,11);
                break;
            case 4:
                lcdWriteString("Astroids have gravity", buffer,0,0);
                lcdWriteString("Gravity causes your", buffer,1,0);
                lcdWriteString("bullets to bend", buffer,2,0);
                lcdWriteString("4",buffer,3,11);
                break;
        }
        lcd_push_buffer((uint8_t*)buffer); //Update display

        read_chars(input,1);

        switch(input[0]){
            case 'b':
                if(helpPage == 1){
                    nextScreen = 0;
                }else{
                    helpPage--;
                    if(helpPage == nPages-1){
                        lcdWriteString("(n)ext",buffer,3,19);
                    }
                }
                break;
            case 'n':
                if(helpPage < nPages){
                    helpPage++;
                    if(helpPage == nPages){
                        lcdWriteString("(m)enu",buffer,3,19);
                    }
                }
                break;
            case 'm':
                if(helpPage == nPages){
                    nextScreen = 0;
                }
        }
    }
}

void screen_stageSelect(char buffer[]){
    memset(buffer, 0x00, 512); //Clear screen

    lcdWriteString("Enter stage # 01-99",buffer,0,0);
    lcdWriteString("Stage:",buffer,1,0);
    lcdWriteString("(b)ack",buffer,3,0);

    lcd_push_buffer((uint8_t*)buffer); //Update display

    uint8_t i, d, n;
    i = 0;
    n = 0;
    while(i < 2){ //Get max two digits
        read_chars(input,1);
        if(input[0] == 'b'){
            //If player presses b, cancel out and go back to main menu
            nextScreen = 0;
            break;
        }
        d = input[0] - '0'; //Get digit value of input
        if(0 <= d && d <= 9){
            //Write value to screen if input is correct
            lcdWriteString(input,buffer,1,7 + i++);
            n = 10 * n + d; //Since the loop runs a maximum of two times, the first value is multiplied by 10
            lcd_push_buffer((uint8_t*)buffer);
        }
        if(i >= 2){ //Only run this part if both numbers are entered
            lcdWriteString("Play this stage?  (y/n)",buffer,2,1);
            lcd_push_buffer((uint8_t*)buffer);

            int cont = 1; //Only exit loop when correct term is entered
            while(cont == 1){
                read_chars(input,1);
                switch(input[0]){
                    case 'y':
                        /*TODO:
                        Set flag to exit menu loop
                        for now, just output to putty*/
                        printf("Game started\n");
                        cont = 0;
                        break;
                    case 'n':
                        //Reset screen
                        cont = 0;
                        break;
                    case 'b':
                        //Go back to main menu
                        nextScreen = 0;
                        cont = 0;
                        break;
                }
            }
        }
    }
}
