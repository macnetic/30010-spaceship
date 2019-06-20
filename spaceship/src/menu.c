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
    if(nextScreen != currentScreen){
        currentScreen = nextScreen;
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

    read_chars(input,1); //Wait for input for next screen

    switch(input[0]){
        case '2':
            nextScreen = 2;
            break;
        case '3':
            nextScreen = 3;
            break;
        default:
            nextScreen = 0;
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

    lcd_push_buffer(buffer); //Update display
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

    read_chars(input,1);
    lcdWriteString(input,buffer,1,7);
    lcd_push_buffer(buffer);
    read_chars(input,1);
    lcdWriteString(input,buffer,1,8);
    lcd_push_buffer(buffer);

    lcdWriteString("Play this stage?  (y/n)",buffer,2,1);

    lcd_push_buffer(buffer);
}
