#include <spaceship.h>

#define lowsmall 220
#define highsmall 223
#define bigSquare 219

#define ESC 0x1B

//const static int heading;

const static char N[] = {lowsmall,ESC,'[','D',ESC,'[','B',bigSquare,ESC,'[','2','D',ESC,'[','B',
                bigSquare,highsmall,bigSquare, ESC,'[','3','D',ESC,'[','B',highsmall,ESC,'[','C', highsmall,'\0'

    };

const static char NW[] = {highsmall,lowsmall,ESC,'[','C',lowsmall,
                 ESC, '[','B',ESC,'[','3','D',
                 lowsmall,bigSquare,highsmall,highsmall,lowsmall,
                 ESC,'[','B',ESC,'[','4','D',
                 highsmall,lowsmall,'\0'
                 };

const static char W[] = {lowsmall,lowsmall,lowsmall,bigSquare,highsmall,highsmall,ESC,
                    '[','3','D',ESC,'[','B',highsmall,highsmall,highsmall, '\0'
                    };

const static char SW[] = {lowsmall,highsmall,ESC,'[','B',ESC,'[','3','D',highsmall,bigSquare,lowsmall,lowsmall,highsmall,
                ESC,'[','B',ESC,'[','6','D',lowsmall,highsmall,ESC,'[','C', highsmall,'\0'
                };

const static char S[] = {lowsmall,ESC,'[','C',lowsmall,ESC,'[','B',ESC,'[','3','D',
                bigSquare,lowsmall,bigSquare,ESC,'[','B',ESC,'[','2','D',
                bigSquare,ESC,'[','B',ESC,'[','D',highsmall,'\0'
                };

const static  char SE[] = {highsmall,lowsmall,ESC,'[','B',ESC,'[','4','D',
                 highsmall,lowsmall,lowsmall,bigSquare,highsmall,
                 ESC,'[','B',ESC,'[','3','D',
                 highsmall,ESC,'[','C',highsmall,lowsmall,'\0'
                };

const static char E[] = {highsmall,highsmall,bigSquare,lowsmall,lowsmall,lowsmall,ESC,
                    '[','6','D',ESC,'[','B',highsmall,highsmall,highsmall, '\0'
                    };

const static  char NE[] = {lowsmall,ESC,'[','C',lowsmall,highsmall,ESC,'[','B',ESC,'[','6','D',
                lowsmall,highsmall,highsmall,bigSquare,lowsmall,ESC,'[','B',ESC,'[','3','D',
                lowsmall,highsmall,'\0'
                };

/** Arrays to hold game entities **/
static Player players[MAX_PLAYERS];
static Enemy enemies[MAX_ENEMIES];
static Asteroid asteroids[MAX_ASTEROIDS];
static Projectile projectiles[MAX_PROJECTILES];
static Powerup powerups[MAX_POWERUPS];

/** Entity spawn functions **/
void spawnPlayer(uint32_t x, uint32_t y, int32_t vx, int32_t vy, uint32_t mass, int32_t hitpoints, uint32_t ammunition, uint32_t heading) {
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
                ammunition << FIX_14_SHIFT,
                heading};

            players[i] = p;
            break;
        }
    }
}

void spawnEnemy(int32_t x, int32_t y, int32_t vx, int32_t vy, int32_t mass, int32_t hitpoints) {
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
                mass << FIX_14_SHIFT,
                hitpoints << FIX_14_SHIFT};

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

bool detectHit(Entity* ent1, Entity * ent2) {
    uint32_t dx, dy;
    bool x_overlap, y_overlap;

    dx = abs(ent1->x - ent2->x);
    dy = abs(ent1->y - ent2->y);

    x_overlap = ((ent1->w + ent2->w) >> 1) < dx;
    y_overlap = ((ent1->h + ent2->h) >> 1) < dy;

    if (x_overlap && y_overlap)
        return true;
    else
        return false;
}

void deleteEntity(Entity* ent) {
    ent->isDeleted = true;
}

void drawPlayer(Player* player){
    fgcolor(2);



    gotoxy(player->entity.x >> FIX_14_SHIFT, player->entity.y >> FIX_14_SHIFT);
    switch (player->heading) { //Redraws the character according to the heading.
        case 0: printf(N); break;
        case 1: printf(NW); break;
        case 2: printf(W); break;
        case 3: printf(SW); break;
        case 4: printf(S); break;
        case 5: printf(SE); break;
        case 6: printf(E); break;
        case 7: printf(NE); break;
    }


}

void initGame(void) {
    spawnPlayer(10,10,0,0,0,0,0,0);
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

}

void drawGame(void) {
    clrscr();

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
                    drawPlayer(&players[i]);
                }
        }
}
