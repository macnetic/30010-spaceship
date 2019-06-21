#ifndef _SPACESHIP_H_
#define _SPACESHIP_H_

// Project imports
#include <entity.h>
#include <player.h>
#include <enemy.h>
#include <asteroid.h>
//#include <figures.h>
#include <ansi.h>
//#include <30010_io.h>

#define THRUST_STATE_ON  1
#define THRUST_STATE_OFF 0

#define GAME_WINDOW_HEIGHT 64
#define GAME_WINDOW_WIDTH 250

/** Maximum simultaneous game entities **/
#define MAX_PLAYERS 1
#define MAX_ASTEROIDS 10
#define MAX_ENEMIES 10
#define MAX_PROJECTILES 100
#define MAX_POWERUPS 10

#define GRAVITY_CONST

typedef struct Projectile {
    Entity entity;
    int32_t damage;
} Projectile;

typedef struct Powerup {
    Entity entity;
    // what kind of powerup?
} Powerup;

void spawnProjectile(int32_t x, int32_t y, int32_t vx, int32_t vy, int32_t damage);


void initGame(void);
void updateGame(void);
void drawGame(void);

void gravity(void); // TODO

#endif // _SPACESHIP_H_
