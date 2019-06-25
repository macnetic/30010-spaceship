#include "timer3_updater.h"

void setup_timer(void) {
    RCC->APB1ENR |= RCC_APB1Periph_TIM3; // Enable clock line to timer 3;
    TIM3->CR1 = 0x0; // Configure timer 2
    TIM3->ARR = 15608; // Set reload value - rundet ned
    TIM3->PSC = 0x28; // Set prescale value

    TIM3->DIER |= 1;

    NVIC_SetPriority(TIM3_IRQn, 0); // Set interrupt priority
    NVIC_EnableIRQ(TIM3_IRQn);           // Enable interrupt

    TIM3->CR1 = 0x1;
}

//Interups
//void TIM3_IRQHandler(void) {
//    //flag to set goes here
//    TIM3->SR &= ~0x0001; // Clear interrupt bit
//}
