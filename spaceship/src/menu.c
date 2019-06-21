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

void invertLine(char buffer[], uint16_t line){
    uint16_t i;
    for(i = 128*line; i < 128*(line+1); i++){
        buffer[i] ^= 0x7F;
    }
}

void addUnderline(char buffer[], uint16_t line){
    uint16_t i;
    for(i = 128*line; i < 128*(line+1); i++){
        buffer[i] |= 0x80;
    }
}

void addRightArrow(char buffer[], uint8_t row, uint8_t col){
    uint16_t pos = col + 128*row;
    buffer[pos]   = 0xFE;
    buffer[pos+1] = 0x7C;
    buffer[pos+2] = 0x38;
    buffer[pos+3] = 0x10;
}

//Different menu screens
void screen_main(char buffer[]){
    memset(buffer, 0x00, 512); //Clear screen

    lcdWriteString("(1) Start game",    buffer,0,0);
    lcdWriteString("(2) Select stage",  buffer,1,0);
    lcdWriteString("(3) Help",          buffer,2,0);
    lcdWriteString("(4) Let's dance!",  buffer,3,0);

    lcd_push_buffer((uint8_t*) buffer); //Update display

    read_chars(input,1); //Wait for input for next screen

    switch(input[0]){
        case '0':
            nextScreen = 0;
            break;
        case '2':
            nextScreen = 2;
            break;
        case '3':
            nextScreen = 3;
            break;
//        default:
            //currentScreen = 1;
    }
}

void screen_help(char buffer[]){
    memset(buffer, 0x00, 512); //Clear screen

    lcdWriteString("bla bla bla", buffer,0,0); //Help text

    lcdWriteString("(b)ack",buffer,3, 0);
    lcdWriteString("1/X",   buffer,3,11);
    lcdWriteString("(n)ext",buffer,3,19);

    lcd_push_buffer(buffer); //Update display
}

void screen_stageSelect(char buffer[]){
    memset(buffer, 0x00, 512); //Clear screen

    lcdWriteString("Enter stage # 01-99",buffer,0,0);
    lcdWriteString("Stage:",buffer,1,0);
    lcdWriteString("(b)ack",buffer,3,0);

    lcd_push_buffer(buffer); //Update display

    uint8_t i, d, n;
    i = 0;
    n = 0;
    while(i < 2){ //Get max two digits
        //TODO: Add black boxes
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
            lcd_push_buffer(buffer);
        }
        if(i >= 2){ //Only run this part if both numbers are entered
            lcdWriteString("Play this stage?  (y/n)",buffer,2,1);
            lcd_push_buffer(buffer);

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
