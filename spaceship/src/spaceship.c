#include <spaceship.h>

/** Arrays to hold game entities **/
static Player players[MAX_PLAYERS];
static Enemy enemies[MAX_ENEMIES];
static Asteroid asteroids[MAX_ASTEROIDS];
static Projectile projectiles[MAX_PROJECTILES];
static Powerup powerups[MAX_POWERUPS];


/*
 * Function clearEntities
 * ----------------------
 * Overwrites the game entity arrays with inactive entities
 */
static void clearEntities(void)
{
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

void initGame(void)
{
    // initialize entity lists with deleted entities
    clearEntities();

    clrscr();

    // Draw window border
    fgcolor(15);
    window(1, 1, GAME_WINDOW_WIDTH, GAME_WINDOW_HEIGHT, "", 1);

    spawnPlayer(&players[0], 100 << FIX_14_SHIFT, 32 << FIX_14_SHIFT, 0, 0, 0, 0, false);

    spawnAsteroid(&asteroids[0], 50 << FIX_14_SHIFT, 25 << FIX_14_SHIFT, 10 << FIX_14_SHIFT, false);
    spawnAsteroid(&asteroids[1], 100 << FIX_14_SHIFT, 40 << FIX_14_SHIFT, 10 << FIX_14_SHIFT, false);
}

/*
 * Function updateGame
 * -------------------
 * Update the game state.
 */
void updateGame(void)
{
    for (uint16_t i = 0; i < MAX_ASTEROIDS; i++)
    {
        if (asteroids[i].entity.isDeleted == false)
        {
//                deleteAsteroidSprite(&asteroids[i]);
        }
    }
    for (uint16_t i = 0; i < MAX_PLAYERS; i++)
    {
        if (players[i].entity.isDeleted == false)
        {
            // Delete old player sprite
            deletePlayerSprite(&players[i]);

            controlPlayer(&players[i]);

            if (players[i].triggerPressed == true)
            {
                // Check if we can spawn a bullet, or if the game limit has been reached
                // TODO: Take all this code and put it into a function
                for (int16_t j = 0; j < MAX_PROJECTILES; j++)
                {
                    if (projectiles[j].entity.isDeleted == true)
                    {
                        int32_t x, y, vx, vy;

                        switch (players[i].heading)
                        {
                        case 0:
                        {
                            x  = 0;
                            y  = -(players[i].entity.h / 2);
                            vx = 0;
                            vy = -(1 << (FIX_14_SHIFT - 1));
                            break;
                        }
                        case 1:
                        {
                            x  = -(players[i].entity.w / 2);
                            y  = -(players[i].entity.h / 2);
                            vx = -(1 << FIX_14_SHIFT);
                            vy = -(1 << (FIX_14_SHIFT - 1));
                            break;
                        }
                        case 2:
                        {
                            x  = -(players[i].entity.w / 2);
                            y  = 0;
                            vx = -(1 << FIX_14_SHIFT);
                            vy = 0;
                            break;
                        }
                        case 3:
                        {
                            x  = -(players[i].entity.w / 2);
                            y  = (players[i].entity.h / 2);
                            vx = -(1 << FIX_14_SHIFT);
                            vy = (1 << (FIX_14_SHIFT - 1));
                            break;
                        }
                        case 4:
                        {
                            x  = 0;
                            y  = (players[i].entity.h / 2);
                            vx = 0;
                            vy = (1 << (FIX_14_SHIFT - 1));
                            break;
                        }
                        case 5:
                        {
                            x  = (players[i].entity.w / 2);
                            y  = (players[i].entity.h / 2);
                            vx = (1 << FIX_14_SHIFT);
                            vy = (1 << (FIX_14_SHIFT - 1));
                            break;
                        }
                        case 6:
                        {
                            x  = (players[i].entity.w / 2);
                            y  = 0;
                            vx = (1 << FIX_14_SHIFT);
                            vy = 0;
                            break;
                        }
                        case 7:
                        {
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
                                        10 << FIX_14_SHIFT, 1 << FIX_14_SHIFT);

                        break;
                    }

                }
                players[i].triggerPressed = false;
            }

            updateEntity(&players[i].entity);
            keepPlayerInBounds(&players[i], 3, 2, GAME_WINDOW_WIDTH - 3, GAME_WINDOW_HEIGHT - 1);
        }
    }

    for (uint16_t j = 0; j < MAX_ASTEROIDS; j++)
    {
        if (asteroids[j].entity.isDeleted == false)
        {

            for (uint16_t i = 0; i < MAX_PROJECTILES; i++)
            {
                if (projectiles[i].entity.isDeleted == false)
                {
                    deleteProjectileSprite(&projectiles[i]);
                    computeGravity(&projectiles[i], &asteroids[i], GRAVITY_CONST);

                    updateEntity(&projectiles[i].entity);
                    if (detectBoundaryBox(&projectiles[i].entity, 2, 2, GAME_WINDOW_WIDTH - 2, GAME_WINDOW_HEIGHT - 1) != 0)
                    {
                        projectiles[i].entity.isDeleted = true;
                    }
                }

            }
        }
    }
}

void drawGame(void)
{
    for (uint16_t i = 0; i < MAX_ASTEROIDS; i++)
    {
        if (asteroids[i].entity.isDeleted == false)
        {
            drawAsteroidSprite(&asteroids[i]);
        }
    }

    for (uint16_t i = 0; i < MAX_ENEMIES; i++)
    {
        if (enemies[i].entity.isDeleted == false)
        {
//                drawEnemy();
        }
    }

    for (uint16_t i = 0; i < MAX_PROJECTILES; i++)
    {
        if (projectiles[i].entity.isDeleted == false)
        {
            drawProjectileSprite(&projectiles[i]);
        }
    }

    for (uint16_t i = 0; i < MAX_POWERUPS; i++)
    {
        if (powerups[i].entity.isDeleted == false)
        {
//                drawPowerup();
        }
    }

    for (uint16_t i = 0; i < MAX_PLAYERS; i++)
    {
        if (players[i].entity.isDeleted == false)
        {
            drawPlayerSprite(&players[i]);
        }
    }

    updateHUD(&players[0]);

    // Hide cursor away
    gotoxy(0,0);
}
