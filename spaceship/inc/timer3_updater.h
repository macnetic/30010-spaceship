#include <stdint.h>
#include <30010_io.h>
#include <stm32f30x_conf.h>

#ifndef _TIM3_H_
#define _TIM3_H_

void setup_timer(void);

//Interups
void TIM3_IRQHandler(void);

#endif // _TIM3_H_
