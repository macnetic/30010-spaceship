#ifndef _POWERUP_H_
#define _POWERUP_H_

#include <entity.h>
#include <figures.h>

#define POWERUP_HITBOX_WIDTH 2 << FIX_14_SHIFT
#define POWERUP_HITBOX_HEIGHT 2 << FIX_14_SHIFT

typedef struct Powerup {
    Entity entity;
    uint8_t type;
} Powerup;

void spawnPowerup(Powerup* powerup, uint32_t x, uint32_t y, uint8_t type, bool isDeleted);

void drawPowerupSprite(Powerup* powerup);
void deletePowerupSprite(Powerup* powerup);

#endif // _POWERUP_H_
