#ifndef _ENEMY_H_
#define _ENEMY_H_

#include <entity.h>

// Placeholder values inserted
#define ENEMY_HITBOX_WIDTH  4
#define ENEMY_HITBOX_HEIGHT 6

/*
 * typedef struct Enemy Enemy
 * --------------------------
 * A struct for keeping track of all variables relating to the player ship.
 *
 * entity:    base properties used for all game entities
 * mass:      mass of player spacecraft
 * hp:        current number of hitpoints left for player
 */
typedef struct Enemy {
    Entity entity;
    uint32_t mass;
    int32_t hp;
} Enemy;

void spawnEnemy(Enemy* enemy, uint32_t x, uint32_t y, uint32_t mass, int32_t hp, bool isDeleted);

#endif // _ENEMY_H_
