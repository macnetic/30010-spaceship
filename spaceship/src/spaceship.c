#include <spaceship.h>

/** Arrays to hold game entities **/
static Player players[MAX_PLAYERS];
static Enemy enemies[MAX_ENEMIES];
static Asteroid asteroids[MAX_ASTEROIDS];
static Projectile projectiles[MAX_PROJECTILES];
static Powerup powerups[MAX_POWERUPS];

bool gameOver = false;
bool enemySpawned = true;
bool powerupSpawned = true;

extern Time t;

/** Helper functions **/
bool isGameOver(void) {
    return gameOver;
}

uint32_t getScore(void) {
    return players[0].score;
}


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

void clearAllSprites(void) {
    for (uint16_t i = 0; i < MAX_ASTEROIDS; i++) {
        if (asteroids[i].entity.isDeleted == false) {
            deleteAsteroidSprite(&asteroids[i]);
        }
    }

    for (uint16_t i = 0; i < MAX_ENEMIES; i++) {
        if (enemies[i].entity.isDeleted == false) {
            deleteEnemySprite(&enemies[i]);
        }
    }

    for (uint16_t i = 0; i < MAX_PROJECTILES; i++) {
        if (projectiles[i].entity.isDeleted == false) {
            deleteProjectileSprite(&projectiles[i]);
        }
    }

    for (uint16_t i = 0; i < MAX_POWERUPS; i++) {
        if (powerups[i].entity.isDeleted == false) {
            deletePowerupSprite(&powerups[i]);
        }
    }

    for (uint16_t i = 0; i < MAX_PLAYERS; i++) {
        if (players[i].entity.isDeleted == false) {
            deletePlayerSprite(&players[i]);
        }
    }
}

/** All the game logic **/
void initGame(void) {
    // initialize entity lists with deleted entities
    clearEntities();

    clrscr();

    // Draw window border
    fgcolor(15);
    window(1, 1, GAME_WINDOW_WIDTH, GAME_WINDOW_HEIGHT, "", 1);
    gotoxy(50,10);
    printf("Hello and Welcome to the cold and relentless outer space.\n");
    printf("%c[49C",ESC);
    printf("You have been put in charge of piloting the only spaceship left in the defense of universe against the x.\n");
    printf("%c[49C",ESC);
    printf("Your objective is to fly around and shoot down as many intruders as possible to help save us all.\n");
    printf("%c[49C",ESC);
    printf("For further information glare upon the glorious LCD screen, controlled by the keyboard \n");
    printf("%c[49C",ESC);
    printf("Good luck.");

    spawnPlayer(&players[0], 100 << FIX_14_SHIFT, 32 << FIX_14_SHIFT, 0, 25, 0, PLAYER_MAX_HP, false);

    spawnAsteroid(&asteroids[0], 50 << FIX_14_SHIFT, 25 << FIX_14_SHIFT, 2 << FIX_14_SHIFT, false);
    spawnAsteroid(&asteroids[1], 100 << FIX_14_SHIFT, 40 << FIX_14_SHIFT, 6 << FIX_14_SHIFT, false);
}

/*
 * Function updateGame
 * -------------------
 * Update the game state.
 */
void updateGame(void) {

    /** Projectile interaction logic **/
    for (uint16_t i = 0; i < MAX_PROJECTILES; i++) {
        // Skip deleted entities
        if (projectiles[i].entity.isDeleted == true) continue;

        // Players
        for (uint16_t j = 0; j < MAX_PLAYERS; j++) {
            // Skip deleted entities
            if (players[j].entity.isDeleted == true) continue;

            // Deal damage to the player and delete the projectile if hit.
            // If the player is dead, flag it and return from function
            if (detectHit(&projectiles[i].entity, &players[j].entity) == true) {
                players[j].hp -= projectiles[i].damage;

                deleteProjectileSprite(&projectiles[i]);
                deleteEntity(&projectiles[i].entity);

                if (players[j].hp <= 0) {
                    gameOver = true;
                    return;
                }
            }
        }

        // Enemies
        for (uint16_t j = 0; j < MAX_ENEMIES; j++) {
            // Skip deleted entities
            if (enemies[j].entity.isDeleted == true) continue;

            // Deal damage to the enemy and delete the projectile if hit
            if (detectHit(&projectiles[i].entity, &enemies[j].entity) == true) {
                enemies[j].hp -= projectiles[i].damage;

                deleteProjectileSprite(&projectiles[i]);
                deleteEntity(&projectiles[i].entity);

                // If enemy dies, delete it, and increment score
                if (enemies[j].hp <= 0) {
                    // TODO Increment score
                    players[0].score += ENEMY_KILL_SCORE;
                    deleteEnemySprite(&enemies[j]);
                    deleteEntity(&enemies[j].entity);
                }
            }
        }

        // Asteroids
        for (uint16_t j = 0; j < MAX_ASTEROIDS; j++) {

            // Skip deleted entities
            if (asteroids[j].entity.isDeleted == true) continue;

            // Delete the projectile if hit
            if (detectHit(&projectiles[i].entity, &asteroids[j].entity) == true) {
                deleteProjectileSprite(&projectiles[i]);
                deleteEntity(&projectiles[i].entity);
            }

            // Compute gravity
            computeGravity(&projectiles[i],&asteroids[j], GRAVITY_CONST);
        }
    }

    // Powerups
    for (uint16_t i = 0; i < MAX_POWERUPS; i++) {
        // Skip deleted entities
        if (powerups[i].entity.isDeleted == true) continue;

        // Players
        for (uint16_t j = 0; j < MAX_PLAYERS; j++) {
            // Skip deleted entities
            if (players[j].entity.isDeleted == true) continue;

            // Deal damage to the player and delete the projectile if hit
            if (detectHit(&powerups[i].entity, &players[j].entity) == true) {
                // TODO Player picks up powerup
                switch (powerups[i].type) {
                case 0: {
                    players[j].ammo += 25;
                    if (players[j].ammo > 25)
                        players[j].ammo = 25;
                    break;
                }
                case 1: {
                    players[j].hp += 5;
                    if (players[j].hp > PLAYER_MAX_HP)
                        players[j].hp = PLAYER_MAX_HP;
                    break;
                }
                }
                deletePowerupSprite(&powerups[i]);
                deleteEntity(&powerups[i].entity);
            }
        }
    }

    // Players
    for (uint16_t i = 0; i < MAX_PLAYERS; i++) {
        if (players[i].entity.isDeleted == false) {
            // Because the heading affects the sprite being drawn, and we update that here, we need to remove the player sprite here
            deletePlayerSprite(&players[i]);

            controlPlayer(&players[i]);

            if (players[i].triggerPressed == true) {
                // Check if we can spawn a bullet, or if the game limit has been reached
                // TODO: Take all this code and put it into a function
                for (int16_t j = 0; j < MAX_PROJECTILES; j++) {
                    if ((projectiles[j].entity.isDeleted == true) && (players[i].ammo > 0)) {
                        int32_t x, y, vx, vy;

                        switch (players[i].heading) {
                        case 0: {
                            x  = 0;
                            y  = -(players[i].entity.h / 2);
                            vx = 0;
                            vy = -(1 << (FIX_14_SHIFT - 1));
                            break;
                        }
                        case 1: {
                            x  = -(players[i].entity.w / 2);
                            y  = -(players[i].entity.h / 2);
                            vx = -(1 << FIX_14_SHIFT);
                            vy = -(1 << (FIX_14_SHIFT - 1));
                            break;
                        }
                        case 2: {
                            x  = -(players[i].entity.w / 2);
                            y  = 0;
                            vx = -(1 << FIX_14_SHIFT);
                            vy = 0;
                            break;
                        }
                        case 3: {
                            x  = -(players[i].entity.w / 2);
                            y  = (players[i].entity.h / 2);
                            vx = -(1 << FIX_14_SHIFT);
                            vy = (1 << (FIX_14_SHIFT - 1));
                            break;
                        }
                        case 4: {
                            x  = 0;
                            y  = (players[i].entity.h / 2);
                            vx = 0;
                            vy = (1 << (FIX_14_SHIFT - 1));
                            break;
                        }
                        case 5: {
                            x  = (players[i].entity.w / 2);
                            y  = (players[i].entity.h / 2);
                            vx = (1 << FIX_14_SHIFT);
                            vy = (1 << (FIX_14_SHIFT - 1));
                            break;
                        }
                        case 6: {
                            x  = (players[i].entity.w / 2);
                            y  = 0;
                            vx = (1 << FIX_14_SHIFT);
                            vy = 0;
                            break;
                        }
                        case 7: {
                            x  = (players[i].entity.w / 2);
                            y  = -(players[i].entity.h / 2);
                            vx = (1 << FIX_14_SHIFT);
                            vy = -(1 << (FIX_14_SHIFT - 1));
                            break;
                        }
                        }

                        spawnProjectile(&projectiles[j],
                                        players[i].entity.x + x, players[i].entity.y + y,
                                        players[i].entity.vx + vx, players[i].entity.vy + vy,
                                        10 << FIX_14_SHIFT, 1);

                        players[i].ammo--;
                        set_led(0x02);


                        break;
                    } else {
                        set_led(0x00);
                    }

                }
                players[i].triggerPressed = false;
            }
        }
    }

    // Clear all sprites after all the hard calculations are done
    clearAllSprites();

    for (uint16_t i = 0; i < MAX_ENEMIES; i++) {
        if (enemies[i].entity.isDeleted == false) {
            updateEntity(&enemies[i].entity);

            // Delete enemy if out of bounds
            if (detectBoundaryBox(&enemies[i].entity, 2, 2, GAME_WINDOW_WIDTH - 2, GAME_WINDOW_HEIGHT - 1) != 0) {
                enemies[i].entity.isDeleted = true;
            }

            if ((rand() % 1000) < 25) {
                for (int16_t j = 0; j < MAX_PROJECTILES; j++) {
                    if (projectiles[j].entity.isDeleted == true) {
                        spawnProjectile(&projectiles[j],
                                        enemies[i].entity.x - (3 << FIX_14_SHIFT), enemies[i].entity.y,
                                        enemies[i].entity.vx - (1 << FIX_14_SHIFT), enemies[i].entity.vy, 1 << FIX_14_SHIFT, 1);
                        break;
                    }
                }
            }
        }
    }

    for (uint16_t i = 0; i < MAX_PROJECTILES; i++) {
        if (projectiles[i].entity.isDeleted == false) {
            // Move projectile
            updateEntity(&projectiles[i].entity);

            // Delete projectile if out of bounds
            if (detectBoundaryBox(&projectiles[i].entity, 2, 2, GAME_WINDOW_WIDTH - 2, GAME_WINDOW_HEIGHT - 1) != 0) {
                projectiles[i].entity.isDeleted = true;
            }
        }
    }

    for (uint16_t i = 0; i < MAX_PLAYERS; i++) {
        if (players[i].entity.isDeleted == false) {
            updateEntity(&players[i].entity);
            keepPlayerInBounds(&players[i], 3, 2, GAME_WINDOW_WIDTH - 3, GAME_WINDOW_HEIGHT - 1);
        }
    }

    if (t.s % 4 == 0) {
        for (uint16_t i = 0; i < MAX_ENEMIES; i++) {
            if ((enemies[i].entity.isDeleted == true) && (enemySpawned == false)) {
                int32_t x, y;
                x = (GAME_WINDOW_WIDTH - 6);
                y = rand() % (GAME_WINDOW_HEIGHT - 4) + 2;
                spawnEnemy(&enemies[i], x << FIX_14_SHIFT, y << FIX_14_SHIFT, -1 << (FIX_14_SHIFT-1), 0, 0, ENEMY_START_HP, false);
                enemySpawned = true;
                break;
            }
        }
    } else {
        enemySpawned = false;
    }


    if (t.s % 10 == 0) {
        for (uint16_t i = 0; i < MAX_POWERUPS; i++) {
            if ((powerups[i].entity.isDeleted == true) && (powerupSpawned == false)) {
                int32_t x, y, type;
                x = rand() % (GAME_WINDOW_WIDTH - 4) + 2;
                y = rand() % (GAME_WINDOW_HEIGHT - 4) + 2;
                type = rand() % 2;
                spawnPowerup(&powerups[i], x << FIX_14_SHIFT, y << FIX_14_SHIFT, type, false);
                powerupSpawned = true;
                break;
            }
        }
    } else {
        powerupSpawned = false;
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
            drawEnemySprite(&enemies[i]);
        }
    }

    for (uint16_t i = 0; i < MAX_PROJECTILES; i++) {
        if (projectiles[i].entity.isDeleted == false) {
            drawProjectileSprite(&projectiles[i]);
        }
    }

    for (uint16_t i = 0; i < MAX_POWERUPS; i++) {
        if (powerups[i].entity.isDeleted == false) {
            drawPowerupSprite(&powerups[i]);
        }
    }

    for (uint16_t i = 0; i < MAX_PLAYERS; i++) {
        if (players[i].entity.isDeleted == false) {
            drawPlayerSprite(&players[i]);
        }
    }

    // Print elapsed game time
    gotoxy(0, GAME_WINDOW_HEIGHT+2);
    fgcolor(15);
    print_time();

    // Hide cursor away
    gotoxy(0,0);

    updateHUD(&players[0]);
}
