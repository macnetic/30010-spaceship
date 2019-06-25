#ifndef _POWERUP_H_
#define _POWERUP_H_

#include <entity.h>
#include <figures.h>

#define POWERUP_HITBOX_WIDTH 2
#define POWERUP_HITBOX_HEIGHT 2

typedef struct Powerup {
    Entity entity;
    uint8_t type;
} Powerup;

void spawnPowerup(Powerup* powerup, uint32_t x, uint32_t y, uint8_t type, bool isDeleted);

#endif // _POWERUP_H_
