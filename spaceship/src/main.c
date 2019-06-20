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


int main(void)
{
    uint16_t length = 1;
    char out[length+1];

    uart_init(916000);
    //clrscr();
    //gotoxy(1,1);
    int8_t *buffer [512];
    //gotoxy(1,1);
//    int8_t *buffer [512];
//
//    lcd_init();
//
//    memset(buffer,0x00,512);
//
//    lcdWriteString("Start press 1", buffer,0,0);
//
//    lcd_push_buffer(buffer);

//    lcd_init();
//    memset(buffer,0x00,512);
//    lcdWriteString("First I wrote this line", buffer,1,0);
//    lcdWriteString("Then this one", buffer,0,5);
//    lcd_push_buffer(buffer);
    uint32_t x=10;
    uint32_t y=10;
    char next;
    uint8_t heading = 0;

    initGame();



    while(1){



    //gotoxy(x++,y++);






    clrscr();

//    heading += rotateSpaceship(heading);
//    heading %= 8;


//    drawSpaceShip(x,y,heading);
    drawGame();




    }
}
