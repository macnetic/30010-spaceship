#ifndef _ASTEROID_H_
#define _ASTEROID_H_

// Project imports
#include <entity.h>
#include <figures.h>
#include <ansi.h>

#define ASTEROID_HITBOX_WIDTH 8
#define ASTEROID_HITBOX_HEIGHT 4


/*
 * typedef struct Asteroid Asteroid
 * --------------------------------
 * A struct for keeping track of all variables relating to an asteroid.
 *
 * entity:    base properties used for all game entities
 * mass:      mass of asteroid
 */
 typedef struct Asteroid {
    Entity entity;
    int32_t mass;
} Asteroid;

void spawnAsteroid(Asteroid* asteroid, uint32_t x, uint32_t y, uint32_t mass, bool isDeleted);

void drawAsteroidSprite(Asteroid* asteroid);
void deleteAsteroidSprite(Asteroid* asteroid);

#endif // _ASTEROID_H_
