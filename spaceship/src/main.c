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
    initGame();

    while(1){
        updateGame();
        drawGame();
    }
}
