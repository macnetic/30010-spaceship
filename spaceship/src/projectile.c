#include <projectile.h>

void spawnProjectile(Projectile* projectile, int32_t x, int32_t y, int32_t vx, int32_t vy, uint32_t mass, uint32_t damage) {
    spawnEntity(&projectile->entity, x, y, vx, vy, 1, 1, false);

    projectile->mass = mass;
    projectile->damage = damage;
}
