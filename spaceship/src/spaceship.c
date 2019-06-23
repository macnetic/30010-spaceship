#include <spaceship.h>

/** Arrays to hold game entities **/
static Player players[MAX_PLAYERS];
static Enemy enemies[MAX_ENEMIES];
static Asteroid asteroids[MAX_ASTEROIDS];
static Projectile projectiles[MAX_PROJECTILES];
static Powerup powerups[MAX_POWERUPS];

///** Entity spawn functions **/
//void spawnPlayer(uint32_t x, uint32_t y, int32_t vx, int32_t vy, uint32_t mass, int32_t hitpoints, uint32_t ammunition, uint32_t heading) {
//    for (uint16_t i = 0; i < MAX_PLAYERS; i++) {
//        // Check if we can put the new projectile here
//        if (~players[i].entity.isDeleted) {
//            Player p = {
//                {
//                    x  << FIX_14_SHIFT,
//                    y  << FIX_14_SHIFT,
//                    vx << FIX_14_SHIFT,
//                    vy << FIX_14_SHIFT,
//                    6  << FIX_14_SHIFT,  // Makeshift value
//                    6  << FIX_14_SHIFT,  // Makeshift value
//                    false},
//                mass << FIX_14_SHIFT,
//                hitpoints << FIX_14_SHIFT,
//                ammunition << FIX_14_SHIFT,
//                heading};
//
//            players[i] = p;
//            break;
//        }
//    }
//}

//void spawnProjectile(int32_t x, int32_t y, int32_t vx, int32_t vy, int32_t damage) {
//    for (uint16_t i = 0; i < MAX_PROJECTILES; i++) {
//        // Check if we can put the new projectile here
//        if (~projectiles[i].entity.isDeleted) {
//            Projectile p = {
//                {
//                    x  << FIX_14_SHIFT,
//                    y  << FIX_14_SHIFT,
//                    vx << FIX_14_SHIFT,
//                    vy << FIX_14_SHIFT,
//                    1  << FIX_14_SHIFT,
//                    1  << FIX_14_SHIFT,
//                    false},
//                damage << FIX_14_SHIFT};
//
//            projectiles[i] = p;
//            break;
//        }
//    }
//}

/*
 * Function clearEntities
 * ----------------------
 * Overwrites the game entity arrays with inactive entities
 */
static void clearEntities(void) {
    for (uint16_t i = 0; i < MAX_ASTEROIDS; i++)
        deleteEntity(&asteroids[i].entity);

    for (uint16_t i = 0; i < MAX_ENEMIES; i++)
        deleteEntity(&enemies[i].entity);

    for (uint16_t i = 0; i < MAX_PROJECTILES; i++)
        deleteEntity(&projectiles[i].entity);

    for (uint16_t i = 0; i < MAX_POWERUPS; i++)
        deleteEntity(&powerups[i].entity);

    for (uint16_t i = 0; i < MAX_PLAYERS; i++)
        deleteEntity(&players[i].entity);
}

void initGame(void) {
    // initialize entity lists with deleted entities
    clearEntities();

    clrscr();

    // Draw window border
    fgcolor(15);
    window(1, 1, GAME_WINDOW_WIDTH, GAME_WINDOW_HEIGHT, "", 1);

    spawnPlayer(&players[0], 200, 40, 0, 0, 0, 0, false);

    spawnAsteroid(&asteroids[0], 50, 25, 100, false);
    spawnAsteroid(&asteroids[1], 100, 40, 100, false);
}

/**
    Kør fysik
    Projectile and asteroid hit detection
    Deal damage
    Delete dead entities
    Power-up hit detection
    Activate power-ups
    etc.

**/
void updateGame(void) {
    for (uint16_t i = 0; i < MAX_ASTEROIDS; i++) {
            if (asteroids[i].entity.isDeleted == false) {
//                deleteAsteroidSprite(&asteroids[i]);
            }
    }
    for (uint16_t i = 0; i < MAX_PLAYERS; i++) {
        if (players[i].entity.isDeleted == false) {
            // Delete old player sprite
            deletePlayerSprite(&players[i]);

            controlPlayer(&players[i]);

            updateEntity(&players[i].entity);
            keepPlayerInBounds(&players[i], 3, 2, GAME_WINDOW_WIDTH - 3, GAME_WINDOW_HEIGHT - 1);
        }
    }
}

void drawGame(void) {
    for (uint16_t i = 0; i < MAX_ASTEROIDS; i++) {
            if (asteroids[i].entity.isDeleted == false) {
                drawAsteroidSprite(&asteroids[i]);
            }
    }

    for (uint16_t i = 0; i < MAX_ENEMIES; i++) {
            if (enemies[i].entity.isDeleted == false) {
//                drawEnemy();
            }
    }

    for (uint16_t i = 0; i < MAX_PROJECTILES; i++) {
            if (projectiles[i].entity.isDeleted == false) {
//                drawProjectile();
            }
    }

    for (uint16_t i = 0; i < MAX_POWERUPS; i++) {
            if (powerups[i].entity.isDeleted == false) {
//                drawPowerup();
            }
    }

    for (uint16_t i = 0; i < MAX_PLAYERS; i++) {
                if (players[i].entity.isDeleted == false) {
                    drawPlayerSprite(&players[i]);
                }
        }

    // Hide cursor away
    gotoxy(0,0);
}
