#ifndef _PLAYER_H_
#define _PLAYER_H_

// Standard library imports
#include <stdlib.h>

// Project imports
#include <entity.h>
#include <figures.h>
#include <30010_io.h>
#include <ansi.h>

// Player constants
#define PLAYER_HITBOX_WIDTH 6
#define PLAYER_HITBOX_HEIGHT 4
#define PLAYER_VEL_SCALE 3
#define PLAYER_MAX_X_VEL 2
#define PLAYER_MAX_Y_VEL 1

/*
 * typedef struct Player Player
 * ----------------------------
 * A struct for keeping track of all variables relating to the player ship.
 *
 * entity:    base properties used for all game entities
 * mass:      mass of player spacecraft
 * ammo:      current number of projectiles left
 * heading:   direction the spaceship is currently pointing
 * hp:        current number of hitpoints left for player
 */
typedef struct Player {
    Entity entity;
    uint32_t mass, ammo, heading;
    int32_t hp;
} Player;

void spawnPlayer(Player* player, uint32_t x, uint32_t y, uint32_t mass, uint32_t ammo, uint32_t heading, int32_t hp, bool isDeleted);

void controlPlayer(Player* player);
void thrustPlayer(Player* player);
void keepPlayerInBounds(Player* player, int32_t x1, int32_t y1, int32_t x2, int32_t y2);

void drawPlayerSprite(Player* player);
void deletePlayerSprite(Player* player);

#endif // _PLAYER_H_
