#include <stdint.h>
#include <stdio.h>
#include "30010_io.h"
//#include <spaceship.h>

#ifndef _FIGURES_H_
#define _FIGURES_H_

// Block characters
#define L_BK 0xDC
#define H_BK 0xDF
#define F_BK 0xDB

#ifndef ESC
#define ESC 0x1B
#endif // ESC

// Terminal cursor movements
#define U_MV 0x41
#define D_MV 0x42
#define F_MV 0x43
#define B_MV 0x44

void drawAsteroid(int x, int y);
//void drawPlayer(Player* player);
uint8_t rotateSpaceship(void);

#endif /* _FIGURES_H_*/
