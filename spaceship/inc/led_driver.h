#include <stm32f30x_conf.h>

#ifndef _LED_DRIVER_H_
#define _LED_DRIVER_H_

#define R_LED_PB4 4
#define G_LED_PC7 7
#define B_LED_PA9 9

/** Led driver functions **/
void init_led(void);
void set_led(uint8_t red, uint8_t green, uint8_t blue);

#endif // _LED_DRIVER_H_
