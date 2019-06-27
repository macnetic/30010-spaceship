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
#include "trig_lut.h"
#include "lcd_driver.h"
#include <wchar.h>
#include "menu.h"
#include <spaceship.h>
#include <timer2.h>

#define BAUD_RATE 1328400

int main(void)
{
    char buffer [512];

    extern Time t;
    setup_timer2();
    start_time();

    uart_init(BAUD_RATE);

    init_led();

    lcd_init();



    // Start message

    initGame();
    // Game loop
    while(1){
        update_time();

        while(nextScreen != 1){
            navigator(&buffer);
        }

        if (t.counter >= 4) {
            updateGame();
            drawGame();
            t.counter = 0;

            if (isGameOver() == true) {
                break;
            }
        }
    }

    clrscr();
    gotoxy(50, 10);
    uint32_t score = getScore();
    printf("GAME OVER.\tScore: %-5lu", score);

    while(1);
}
