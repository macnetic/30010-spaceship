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
//#include "sound_driver.h"
#include "trig_lut.h"
#include "lcd_driver.h"
#include <wchar.h>
#include "menu.h"



int main(void)
{

    uart_init(9600);
    //clrscr();
    //gotoxy(1,1);
    char buffer [512];

    char out[2];
    //gotoxy(1,1);

    lcd_init();

    //screen_main(&buffer);
    nextScreen = 0;

    while(1){
        navigator(&buffer);
    }
}
