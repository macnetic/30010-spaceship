#include <stdint.h>
#include <stdio.h>
#include "lcd_driver.h"
#include "trig_lut.h"
#include "30010_io.h"
#include "charset.h"
#include "menu.h"
#define ESC 0x1B


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

