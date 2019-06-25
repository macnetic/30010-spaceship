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
#include <spaceship.h>
#include <timer2.h>

#define BAUD_RATE 1382400

int main(void)
{
    char buffer [512];

    extern Time t;
    setup_timer2();
    start_time();

    uart_init(BAUD_RATE);

    init_led();

    lcd_init();

    initGame();

    // Start message
    gotoxy(50,10);
    printf("Hello and Welcome to the cold and relentless outer space.\n");
    printf("%c[49C",ESC);
    printf("You have been put in charge of piloting the only spaceship left in the defense of universe against the x.\n");
    printf("%c[49C",ESC);
    printf("Your objective is to fly around and shoot down as many intruders as possible to help save us all.\n");
    printf("%c[49C",ESC);
    printf("For further information glare upon the glorious LCD screen, controlled by the keyboard \n");
    printf("%c[49C",ESC);
    printf("Good luck.");

    while(1){
        update_time();

        while(nextScreen != 1){
            navigator(&buffer);
        }

        if (t.counter >= 4) {
            updateGame();
            drawGame();
            t.counter = 0;
            //TODO: Exit loop when dead
        }
    }
}
