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

#define BAUD_RATE 921600

volatile uint8_t frame_trigger;

void TIM3_IRQHandler(void) {
    frame_trigger = 1;

    TIM3->SR &=~0x0001; // Clear interrupt bit
}


int main(void)
{
    extern Time t;
    setup_timer2();
    start_time();

    uart_init(BAUD_RATE);
//    TIM_TimeBaseInitTypeDef TIM_TimeBaseStruct;
//
//    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
//
//    TIM_TimeBaseStruct.TIM_Prescaler = 17;
//    TIM_TimeBaseStruct.TIM_Period = 62754;
//
//    TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStruct);
//
//    NVIC_SetPriority(TIM3_IRQn, 0);
//    NVIC_EnableIRQ(TIM3_IRQn);
//
//    TIM_Cmd(TIM3, ENABLE);

    initGame();

    //clrscr();
    //gotoxy(1,1);
    char buffer [512];
//
//    char out[2];
//    //gotoxy(1,1);
//
//    lcd_init();
//
//    //screen_main(&buffer);
////    nextScreen = 0;
//
////    char buffer[512];
    lcd_init();
    memset(buffer, 0x00, 512);
    lcd_push_buffer((uint8_t*) buffer);

    char heart[] = {0x5f + 0x20, 0x60 + 0x20, '\0'};

    lcdWriteString(heart, buffer, 0, 0);
//    lcdWriteSymbol(95, buffer, 1, 0);
//    lcdWriteSymbol(96, buffer, 1, 1);
    lcd_push_buffer((uint8_t*) buffer);


    while(1){
//        navigator(&buffer);

        if (t.hs >= 2) {
            updateGame();
            drawGame();
            t.hs = 0;
        }
    }
}
