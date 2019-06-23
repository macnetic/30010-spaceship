#include <asteroid.h>

const static char asteroid_sprite[] = {
    ESC, '[', '2', B_MV, ESC, '[', U_MV,
    L_BK, F_BK, F_BK, F_BK, L_BK, ESC, '[', D_MV, ESC, '[', '6', B_MV,
    F_BK, F_BK, F_BK, F_BK, F_BK, F_BK, F_BK, ESC, '[', D_MV, ESC, '[', '7', B_MV,
    H_BK, F_BK, F_BK, F_BK, F_BK, F_BK, H_BK, ESC, '[', D_MV, ESC, '[', '5', B_MV,
    H_BK, H_BK, H_BK, '\0'
};

const static char asteroid_delete_sprite[] = {
    ESC, '[', '2', B_MV, ESC, '[', U_MV,
    ' ', ' ', ' ', ' ', ' ', ESC, '[', D_MV, ESC, '[', '6', B_MV,
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ESC, '[', D_MV, ESC, '[', '7', B_MV,
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ESC, '[', D_MV, ESC, '[', '5', B_MV,
    ' ', ' ', ' ', '\0'
};

void spawnAsteroid(Asteroid* asteroid, uint32_t x, uint32_t y, uint32_t mass, bool isDeleted) {
    spawnEntity(&asteroid->entity, x, y, 0, 0, ASTEROID_HITBOX_WIDTH, ASTEROID_HITBOX_HEIGHT, isDeleted);

    asteroid->mass = mass;
}

/*
 * Function drawAsteroidSprite
 * ---------------------------
 * Draws an asteroid in the game.
 */
void drawAsteroidSprite(Asteroid* asteroid) {
    fgcolor(3);

    gotoxy(asteroid->entity.x >> FIX_14_SHIFT, asteroid->entity.y >> FIX_14_SHIFT);
    printf(asteroid_sprite);
}

/*
 * Function deleteAsteroidSprite
 * -----------------------------
 * Overwrite the sprite of an asteroid in the game with spaces, ready to redraw updated asteroid.
 * Since asteroids are stationary in our game, we don't need this function anyway,
 * but I had already implemented, so why not just keep it?
 */
void deleteAsteroidSprite(Asteroid* asteroid) {
    gotoxy(asteroid->entity.x >> FIX_14_SHIFT, asteroid->entity.y >> FIX_14_SHIFT);
    printf(asteroid_delete_sprite);
}
