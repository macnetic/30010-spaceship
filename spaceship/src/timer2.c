#include "timer2.h"

extern volatile Time t = {0, 0, 0, 0};

/** Timer configuration **/
void setup_timer2(void) {
    /* TIM2 configuration */
    RCC->APB1ENR |= RCC_APB1Periph_TIM2; // Enable clock line to Timer 2
    TIM2->CR1 = 0x0000; // Default configuration
    TIM2->PSC = TIM2_PSC;
    TIM2->ARR = TIM2_RELOAD;
    TIM2->DIER |= 0x0001; // Update interrupt enabled

    // Enable interrupt in NVIC
    NVIC_SetPriority(TIM2_IRQn, 0);
    NVIC_EnableIRQ(TIM2_IRQn);
}

void TIM2_IRQHandler(void) {
    t.hs += 1;
    t.counter += 1;

    TIM2->SR &=~0x0001; // Clear interrupt bit
}


/** Timekeeping **/
void update_time(void) {
     if (t.hs >= 100) {
        t.hs = 0;
        if (++t.s >= 60) {
            t.s = 0;
            if (++t.m >= 60) {
                t.m = 0;
                t.h += 1;
            }
        }
    }
}

void start_time(void) {
    TIM2->CR1 |= 0x0001;
}

void stop_time(void) {
    TIM2->CR1 &= ~0x0001;
}

void reset_time(void) {
    t.h = 0;
    t.m = 0;
    t.s = 0;
    t.hs = 0;
}

void print_time(void) {
    printf("%02d:%02d:%02d\n", t.h, t.m, t.s);
}

/** PWM ***/
