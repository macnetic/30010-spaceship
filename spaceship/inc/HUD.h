#include <stdint.h>
#include <stdio.h>
#include "lcd_driver.h"
#include "trig_lut.h"
#include "30010_io.h"
#include "charset.h"
#include "player.h"

#ifndef _HUD_H_
#define _HUD_H_

void updateHUD(Player * player);

#endif
