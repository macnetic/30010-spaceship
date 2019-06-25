#ifndef _PROJECTILE_H_
#define _PROJECTILE_H_

// Project imports
#include <entity.h>
#include <asteroid.h>

#define PROJECTILE_HITBOX_WIDTH 1 << FIX_14_SHIFT
#define PROJECTILE_HITBOX_HEIGHT 1 << FIX_14_SHIFT

typedef struct Projectile {
    Entity entity;
    uint32_t mass, damage;
} Projectile;

void spawnProjectile(Projectile* projectile, int32_t x, int32_t y, int32_t vx, int32_t vy, uint32_t mass, uint32_t damage);

void computeGravity(Projectile* projectile, Asteroid* Asteroid, uint32_t g_const);

void drawProjectileSprite(Projectile* projectile);
void deleteProjectileSprite(Projectile* projectile);

#endif // _PROJECTILE_H_
