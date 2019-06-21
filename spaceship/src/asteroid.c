#include <asteroid.h>

void spawnAsteroid(Asteroid* asteroid, uint32_t x, uint32_t y, uint32_t mass) {
    spawnEntity(&asteroid->entity, x, y, 0, 0, ASTEROID_HITBOX_WIDTH, ASTEROID_HITBOX_HEIGHT);

    asteroid->mass = mass;
}
