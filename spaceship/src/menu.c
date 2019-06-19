#include <stdint.h>
#include <stdio.h>
#include "lcd_driver.h"
#include "trig_lut.h"
#include "30010_io.h"
#include "charset.h"
#include "menu.h"
#define ESC 0x1B

void invertLine(char *buffer, uint8_t index){
    uint8_t i;
    for(i = 128*index; i < 128*(index+1); i++){
        buffer[i] ^= 0xFF;
    }
}
