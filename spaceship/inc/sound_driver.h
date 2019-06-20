#include <stdint.h>
#include "30010_io.h"

#ifndef _SOUND_DRIVER_H_
#define _SOUND_DRIVER_H_

#define PRESCALER_VALUE 9
void init_sound();
void setFreq(uint16_t freq);
void switchOnOff(); //TODO

#endif // _SOUND_DRIVER_H_
