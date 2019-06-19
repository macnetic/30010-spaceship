#include <spaceship.h>

/** Arrays to hold game entities **/
static Player players[MAX_PLAYERS];
static Enemy enemies[MAX_ENEMIES];
static Asteroid asteroids[MAX_ASTEROIDS];
static Projectile projectiles[MAX_PROJECTILES];

/** Entity spawn functions **/
void spawnPlayer(int32_t x, int32_t y, int32_t vx, int32_t vy, int32_t mass, int32_t hitpoints, int32_t ammunition) {
    for (uint16_t i = 0; i < MAX_PLAYERS; i++) {
        // Check if we can put the new projectile here
        if (~players[i].entity.isDeleted) {
            Player p = {
                {
                    x  << FIX_14_SHIFT,
                    y  << FIX_14_SHIFT,
                    vx << FIX_14_SHIFT,
                    vy << FIX_14_SHIFT,
                    6  << FIX_14_SHIFT,  // Makeshift value
                    6  << FIX_14_SHIFT,  // Makeshift value
                    false},
                mass << FIX_14_SHIFT,
                hitpoints << FIX_14_SHIFT,
                ammunition << FIX_14_SHIFT};

            players[i] = p;
            break;
        }
    }
}

void spawnEnemy(int32_t x, int32_t y, int32_t vx, int32_t vy, int32_t damage) {
    for (uint16_t i = 0; i < MAX_PROJECTILES; i++) {
        // Check if we can put the new projectile here
        if (~enemies[i].entity.isDeleted) {
            Enemy e = {
                {
                    x  << FIX_14_SHIFT,
                    y  << FIX_14_SHIFT,
                    vx << FIX_14_SHIFT,
                    vy << FIX_14_SHIFT,
                    6  << FIX_14_SHIFT,  // Makeshift value
                    4  << FIX_14_SHIFT,  // Makeshift value
                    false},
                damage << FIX_14_SHIFT};

            enemies[i] = e;
            break;
        }
    }
}

void spawnProjectile(int32_t x, int32_t y, int32_t vx, int32_t vy, int32_t damage) {
    for (uint16_t i = 0; i < MAX_PROJECTILES; i++) {
        // Check if we can put the new projectile here
        if (~projectiles[i].entity.isDeleted) {
            Projectile p = {
                {
                    x  << FIX_14_SHIFT,
                    y  << FIX_14_SHIFT,
                    vx << FIX_14_SHIFT,
                    vy << FIX_14_SHIFT,
                    1  << FIX_14_SHIFT,
                    1  << FIX_14_SHIFT,
                    false},
                damage << FIX_14_SHIFT};

            projectiles[i] = p;
            break;
        }
    }
}

void spawnAsteroid(int32_t x, int32_t y, int32_t mass) {
    for (uint16_t i = 0; i < MAX_ASTEROIDS; i++) {
        // Check if we can put the new asteroid here
        if (~asteroids[i].entity.isDeleted) {
            Asteroid a = {
                {
                    x << FIX_14_SHIFT,
                    y << FIX_14_SHIFT,
                    0 << FIX_14_SHIFT,
                    0 << FIX_14_SHIFT,
                    7 << FIX_14_SHIFT,
                    5 << FIX_14_SHIFT},
                mass << FIX_14_SHIFT};

            asteroids[i] = a;
            break;
        }
    }
}

//bool detectHit(Entity * ent1, Entity * ent2) {
//    uint32_t dx, dy;
//    dx = abs(ent1->x - ent2->x);
//    dy = abs(ent1->y - ent2->y);
//
//    if ((dx <= player->w) & (dy <= player->h))
//        return true;
//    else
//        return false;
//}

//for (uint16_t i = 0; i < MAX_PROJECTILES; i++) {
//    if (projectile_entities[i].isDeleted == STATE_NOT_DELETED) {
//        for (uint16_t j = 0; j < MAX_PLAYERS; j++) {
//        }
//    }
//}
