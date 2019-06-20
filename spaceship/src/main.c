/*
**
**                           Main.c
**
**
**********************************************************************/
/*
   Last committed:     $Revision: 00 $
   Last changed by:    $Author: $
   Last changed date:  $Date:  $
   ID:                 $Id:  $

**********************************************************************/
#include "stm32f30x_conf.h"
#include <stdio.h>
#include <stdint.h>
#include "30010_io.h"
#include "ansi.h"
#include "sound_driver.h"
#include "trig_lut.h"
#include "lcd_driver.h"
#include <wchar.h>
#include <spaceship.h>



int main(void)
{
    uart_init(916000);

    initGame();

    char buffer[512];
    lcd_init();
    memset(buffer, 0x00, 512);
    lcd_push_buffer((uint8_t*) buffer);

    char heart[] = {0x5f + 0x20, 0x60 + 0x20, '\0'};

    lcdWriteString(heart, buffer, 0, 0);
//    lcdWriteSymbol(95, buffer, 1, 0);
//    lcdWriteSymbol(96, buffer, 1, 1);
    lcd_push_buffer((uint8_t*) buffer);


    while(1){
        updateGame();
        drawGame();
    }
}
