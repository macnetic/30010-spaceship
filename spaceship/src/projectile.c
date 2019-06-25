#include <projectile.h>

const char projectile_sprite[] = "*";
const char projectile_delete_sprite[] = " ";

void spawnProjectile(Projectile* projectile, int32_t x, int32_t y, int32_t vx, int32_t vy, uint32_t mass, uint32_t damage) {
    spawnEntity(&projectile->entity, x, y, vx, vy, PROJECTILE_HITBOX_WIDTH, PROJECTILE_HITBOX_HEIGHT, false);

    projectile->mass = mass;
    projectile->damage = damage;
}

/*
 * Function computeGravity
 * -----------------------
 * Applies gravity to projectiles from asteroids.
 *
 * projectile:   pointer to Projectile
 * asteroid:     pointer to Asteroid
 */
void computeGravity(Projectile* projectile, Asteroid* asteroid, uint32_t g_const) {
    static uint32_t d, gravity;
    static int32_t dx, dy;

    // Compute distance, using integer precision, otherwise we run out of space fast
    dx = asteroid->entity.x - projectile->entity.x;
    dy = asteroid->entity.y - projectile->entity.y;
    d = abs(dx) + abs(dy);

    gravity = FIX_14_DIV(FIX_14_MULT(g_const, asteroid->mass), FIX_14_MULT(FIX_14_MULT(d,d),d));


    if (dx < 0)
        projectile->entity.vx -= FIX_14_DIV(FIX_14_MULT(gravity, abs(dx)), d);
    else
        projectile->entity.vx += FIX_14_DIV(FIX_14_MULT(gravity, abs(dx)), d);

    if (dy < 0)
        projectile->entity.vy -= FIX_14_DIV(FIX_14_MULT(gravity, abs(dy)), d);
    else
        projectile->entity.vy += FIX_14_DIV(FIX_14_MULT(gravity, abs(dy)), d);
}

void drawProjectileSprite(Projectile* projectile) {
    fgcolor(10);
    drawSprite(&projectile->entity, projectile_sprite);
}

void deleteProjectileSprite(Projectile* projectile) {
    drawSprite(&projectile->entity, projectile_delete_sprite);
}
