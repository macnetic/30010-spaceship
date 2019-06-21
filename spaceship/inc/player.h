#ifndef _PLAYER_H_
#define _PLAYER_H_

// Project imports
#include <entity.h>
#include <figures.h>
#include <30010_io.h>
#include <ansi.h>

// Player constants
#define PLAYER_HITBOX_WIDTH 6
#define PLAYER_HITBOX_HEIGHT 4

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


void spawnPlayer(Player* player, uint32_t x, uint32_t y, uint32_t mass, uint32_t ammo, uint32_t heading, int32_t hp);

void controlPlayer(Player* player);

void drawPlayerSprite(Player* player);
void deletePlayerSprite(Player* player);

#endif // _PLAYER_H_
