#include <entity.h>

/*
 * Function spawnEntity
 * --------------------
 * Spawns an Entity instance in the game.
 *
 * x, y:        position
 * vx, vy:      velocity
 * w, h:        hit box dimensions, used for collision detection
 * isDeleted:   flag to keep track of whether a game entity is currently active in the game
 */
void spawnEntity(Entity* ent, uint32_t x, uint32_t y, int32_t vx, int32_t vy, uint32_t w, uint32_t h) {
    ent->x = x << FIX_14_SHIFT;
    ent->y = y << FIX_14_SHIFT;
    ent->vx = vx << FIX_14_SHIFT;
    ent->vy = vx << FIX_14_SHIFT;
    ent->w = w << FIX_14_SHIFT;
    ent->h = h << FIX_14_SHIFT;

    ent->isDeleted = false;
}

/*
 * Function deleteEntity
 * ---------------------
 * Marks an Entity as deleted.
 */
void deleteEntity(Entity* ent) {
    ent->isDeleted = true;
}

void updateEntity(Entity* ent) {
    ent->x += ent->vx;
    ent->y += ent->vy;
}

/*
 * Function detectHit
 * ------------------
 * Detects if two Entity instances are colliding, using simple rectangular hitboxes.
 *
 * ent_a, ent_b:   Entity instances being checked for collision
 *
 * returns: true if a collision is detected, false otherwise
 */
bool detectHit(Entity* ent_a, Entity * ent_b) {
    uint32_t dx, dy;
    bool x_overlap, y_overlap;

    dx = abs(ent_a->x - ent_b->x);
    dy = abs(ent_a->y - ent_b->y);

    x_overlap = ((ent_a->w + ent_b->w) >> 1) < dx;
    y_overlap = ((ent_a->h + ent_b->h) >> 1) < dy;

    if (x_overlap && y_overlap)
        return true;
    else
        return false;
}
