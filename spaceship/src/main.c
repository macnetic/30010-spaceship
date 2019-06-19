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
#include "stdio.h"
#include "30010_io.h"
#include "ansi.h"
#include "sound_driver.h"
#include "trig_lut.h"
#include "lcd_driver.h"

int main(void)
{
    uint16_t length = 1;
    char out[length+1];

    uart_init(115200);
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
    int x=0;
    int y=0;
    char next;

    while(1){


    read_chars(out, length);
//    printf("%s", out);
    next = out[0];

    if (next == 0x38){
        y--;
    } else if (next == 0x36) {
        x++;
    } else if (next == 0x32) {
        y++;
    } else if (next == 0x34) {
        x--;
    }
     else if (next == 0x31) {
        x--;
        y++;
    }
     else if (next == 0x33) {
        x++;
        y++;
    }
     else if (next == 0x37) {
        x--;
        y--;
    }
     else if (next == 0x39) {
        x++;
        y--;
    }










    while(1){


    read_chars(out, length);
    printf("%s", out);

    next = out[0];

    if (next == 0x38){
        y--;
    } else if (next == 0x36) {
        x++;
    } else if (next == 0x32) {
        y++;
    } else if (next == 0x34) {
        x--;
    }
     else if (next == 0x31) {
        x--;
        y++;
    }
     else if (next == 0x33) {
        x++;
        y++;
    }
     else if (next == 0x37) {
        x--;
        y--;
    }
     else if (next == 0x39) {
        x++;
        y--;
    }
    clrscr();
    drawSpaceShip(x,y);
//    for (int i = 0; i <= length; i++)
//        printf("%02x ", out[i]);
    }
}
