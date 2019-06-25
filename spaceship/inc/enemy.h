#ifndef _ENEMY_H_
#define _ENEMY_H_

#include <entity.h>
#include <figures.h>

// Placeholder values inserted
#define ENEMY_HITBOX_WIDTH  4 << FIX_14_SHIFT
#define ENEMY_HITBOX_HEIGHT 3 << FIX_14_SHIFT

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

void spawnEnemy(Enemy* enemy, uint32_t x, uint32_t y, uint32_t vx, uint32_t vy, uint32_t mass, int32_t hp, bool isDeleted);

void drawEnemySprite(Enemy* enemy);
void deleteEnemySprite(Enemy* enemy);

#endif // _ENEMY_H_
