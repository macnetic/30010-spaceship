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

//void spawnEnemy(int32_t x, int32_t y, int32_t vx, int32_t vy, int32_t mass, int32_t hitpoints) {
//    for (uint16_t i = 0; i < MAX_PROJECTILES; i++) {
//        // Check if we can put the new projectile here
//        if (~enemies[i].entity.isDeleted) {
//            Enemy e = {
//                {
//                    x  << FIX_14_SHIFT,
//                    y  << FIX_14_SHIFT,
//                    vx << FIX_14_SHIFT,
//                    vy << FIX_14_SHIFT,
//                    6  << FIX_14_SHIFT,  // Makeshift value
//                    4  << FIX_14_SHIFT,  // Makeshift value
//                    false},
//                mass << FIX_14_SHIFT,
//                hitpoints << FIX_14_SHIFT};
//
//            enemies[i] = e;
//            break;
//        }
//    }
//}

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

//void spawnAsteroid(int32_t x, int32_t y, int32_t mass) {
//    for (uint16_t i = 0; i < MAX_ASTEROIDS; i++) {
//        // Check if we can put the new asteroid here
//        if (~asteroids[i].entity.isDeleted) {
//            Asteroid a = {
//                {
//                    x << FIX_14_SHIFT,
//                    y << FIX_14_SHIFT,
//                    0 << FIX_14_SHIFT,
//                    0 << FIX_14_SHIFT,
//                    7 << FIX_14_SHIFT,
//                    5 << FIX_14_SHIFT},
//                mass << FIX_14_SHIFT};
//
//            asteroids[i] = a;
//            break;
//        }
//    }
//}

void initGame(void) {
    clrscr();

    // Draw window border
    fgcolor(15);
    window(1, 1, GAME_WINDOW_WIDTH, GAME_WINDOW_HEIGHT, "", 1);

    spawnPlayer(&players[0], 10, 10, 0, 0, 0, 0);
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
    for (uint16_t i = 0; i < MAX_PLAYERS; i++) {
        if (~players[i].entity.isDeleted) {
            deletePlayerSprite(&players[i]);
            controlPlayer(&players[i]);

            if ((players[i].entity.x - players[i].entity.w / 2) <= (1 << FIX_14_SHIFT))
                players[i].entity.x = (players[i].entity.w / 2) + (1 << FIX_14_SHIFT);
            else if ((players[i].entity.x + players[i].entity.w / 2) > (GAME_WINDOW_WIDTH << FIX_14_SHIFT))
                players[i].entity.x = (GAME_WINDOW_WIDTH - 1) << FIX_14_SHIFT;

            if ((players[i].entity.y - players[i].entity.h / 2) < 1 << FIX_14_SHIFT)
                players[i].entity.y = 2 << FIX_14_SHIFT;
            if ((players[i].entity.y + players[i].entity.h / 2) >= (GAME_WINDOW_HEIGHT << FIX_14_SHIFT))
                players[i].entity.y = (GAME_WINDOW_HEIGHT - 1) << FIX_14_SHIFT;
        }
    }
}

void drawGame(void) {
    for (uint16_t i = 0; i < MAX_ASTEROIDS; i++) {
            if (~asteroids[i].entity.isDeleted) {
//                drawAsteroid();
            }
    }

    for (uint16_t i = 0; i < MAX_ENEMIES; i++) {
            if (~enemies[i].entity.isDeleted) {
//                drawEnemy();
            }
    }

    for (uint16_t i = 0; i < MAX_PROJECTILES; i++) {
            if (~projectiles[i].entity.isDeleted) {
//                drawProjectile();
            }
    }

    for (uint16_t i = 0; i < MAX_POWERUPS; i++) {
            if (~powerups[i].entity.isDeleted) {
//                drawPowerup();
            }
    }

    for (uint16_t i = 0; i < MAX_PLAYERS; i++) {
                if (~players[i].entity.isDeleted) {
                    drawPlayerSprite(&players[i]);
                }
        }
}
