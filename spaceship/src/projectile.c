#include <projectile.h>

const char projectile_sprite[] = "*";
const char projectile_delete_sprite[] = " ";

void spawnProjectile(Projectile* projectile, int32_t x, int32_t y, int32_t vx, int32_t vy, uint32_t mass, uint32_t damage) {
    spawnEntity(&projectile->entity, x, y, vx, vy, 1, 1, false);

    projectile->mass = mass;
    projectile->damage = damage;
}

void drawProjectileSprite(Projectile* projectile) {
    fgcolor(10);
    drawSprite(&projectile->entity, projectile_sprite);
}

void deleteProjectileSprite(Projectile* projectile) {
    drawSprite(&projectile->entity, projectile_delete_sprite);
}
