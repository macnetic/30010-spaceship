#ifndef _TIMER2_H_
#define _TIMER2_H_

/** Symbolic constant definitions **/
#define TIM2_PSC 15 // Prescale so 100 Hz reload value fits in 16 bits
#define TIM2_RELOAD 39999 // Reload value for 100 Hz and prescale 15

typedef struct {
    uint8_t m, s, hs;
    uint16_t h;
} time;

volatile time t = {0, 0, 0, 0};

/** Timer2 configuration functions **/
void setup_timer2(void);

/** Interrupt handlers **/
void TIM2_IRQHandler(void);

/** Timekeeping functions **/
void update_time(void);
void start_time(void);
void stop_time(void);
void reset_time(void);

/** PWM functions **/


#endif // _TIMER2_H_
