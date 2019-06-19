#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <trig_lut.h>

#ifndef _SPACESHIP_H_
#define _SPACESHIP_H_

#define THRUST_STATE_ON  1
#define THRUST_STATE_OFF 0

/** Maximum simultaneous game entities **/
#define MAX_PLAYERS 1
#define MAX_ASTEROIDS 10
#define MAX_ENEMIES 10
#define MAX_PROJECTILES 100
#define MAX_POWERUPS 10

#define GRAVITY_CONST

typedef struct Entity {
    int32_t x, y;
    int32_t vx, vy;
    int32_t w, h;
    bool isDeleted;
} Entity;

typedef struct Player {
    Entity entity;
    int32_t mass, hitpoints, ammunition;
} Player;

typedef struct Enemy {
    Entity entity;
    int32_t mass, hitpoints;
} Enemy;

typedef struct Asteroid {
    Entity entity;
    int32_t mass;
} Asteroid;

typedef struct Projectile {
    Entity entity;
    int32_t damage;
} Projectile;

typedef struct Powerup {
    Entity entity;
    // what kind of powerup?
} Powerup;

void spawnPlayer(int32_t x, int32_t y, int32_t vx, int32_t vy, int32_t mass, int32_t hitpoints, int32_t ammunition);
void spawnEnemy(int32_t x, int32_t y, int32_t vx, int32_t vy, int32_t mass, int32_t hitpoints);
void spawnProjectile(int32_t x, int32_t y, int32_t vx, int32_t vy, int32_t damage);
void spawnAsteroid(int32_t x, int32_t y, int32_t mass);

void deleteEntity(Entity * ent);

bool detectHit(Entity* ent1, Entity* ent2);

void updateGame(void);
void drawGame(void);

void gravity(void);

#endif // _SPACESHIP_H_
