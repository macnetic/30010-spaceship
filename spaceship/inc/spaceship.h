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

#define STATE_DELETED 0
#define STATE_NOT_DELETED 1

#define HIT 1
#define NO_HIT 0

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

void spawnPlayer(int32_t x, int32_t y, int32_t vx, int32_t vy, int32_t mass, int32_t hitpoints, int32_t ammunition);
void spawnEnemy(int32_t x, int32_t y, int32_t vx, int32_t vy, int32_t damage);
void spawnProjectile(int32_t x, int32_t y, int32_t vx, int32_t vy, int32_t damage);
void spawnAsteroid(int32_t x, int32_t y, int32_t mass);

bool detectHit(Entity* ent1, Entity* ent2);

void gravity(void);

#endif // _SPACESHIP_H_
