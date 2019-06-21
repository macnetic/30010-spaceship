#ifndef _ENTITY_H_
#define _ENTITY_H_

// Standard library imports
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

// Project imports
#include <trig_lut.h>

/*
 * typedef struct Entity Entity
 * ----------------------------
 * A struct for keeping track of all variables relating to the player ship.
 *
 * x, y:     position
 * vx, vy:   velocity
 * w, h:     hit box dimensions, used for collision detection
 * isDeleted:   flag to keep track of whether a game entity is currently active in the game
 */
typedef struct Entity {
    uint32_t x, y;
    int32_t vx, vy;
    uint32_t w, h;
    bool isDeleted;
} Entity;

void spawnEntity(Entity* ent, uint32_t x, uint32_t y, int32_t vx, int32_t vy, uint32_t width, uint32_t height);

void deleteEntity(Entity* ent);

bool detectHit(Entity* ent_a, Entity* ent_b);

#endif // _ENTITY_H_
