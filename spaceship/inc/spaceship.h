#ifndef _SPACESHIP_H_
#define _SPACESHIP_H_

// Project imports
#include <entity.h>
#include <player.h>
#include <enemy.h>
#include <asteroid.h>
#include <projectile.h>
//#include <figures.h>
#include <ansi.h>
//#include <30010_io.h>

#define THRUST_STATE_ON  1
#define THRUST_STATE_OFF 0

#define GAME_WINDOW_HEIGHT 64
#define GAME_WINDOW_WIDTH 200

/** Maximum simultaneous game entities **/
#define MAX_PLAYERS 1
#define MAX_ASTEROIDS 5
#define MAX_ENEMIES 5
#define MAX_PROJECTILES 20
#define MAX_POWERUPS 5

#define GRAVITY_CONST

typedef struct Powerup {
    Entity entity;
    // what kind of powerup?
} Powerup;

void initGame(void);
void updateGame(void);
void drawGame(void);

void gravity(void); // TODO

#endif // _SPACESHIP_H_
