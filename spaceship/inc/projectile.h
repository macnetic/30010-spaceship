#ifndef _PROJECTILE_H_
#define _PROJECTILE_H_

// Project imports
#include <entity.h>

typedef struct Projectile {
    Entity entity;
    uint32_t mass, damage;
} Projectile;

void spawnProjectile(Projectile* projectile, int32_t x, int32_t y, int32_t vx, int32_t vy, uint32_t mass, uint32_t damage);

#endif // _PROJECTILE_H_
