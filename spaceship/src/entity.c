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
void spawnEntity(Entity* ent, uint32_t x, uint32_t y, int32_t vx, int32_t vy, uint32_t w, uint32_t h, bool isDeleted) {
    ent->x = x;
    ent->y = y;
    ent->vx = vx;
    ent->vy = vy;
    ent->w = w;
    ent->h = h;

    ent->isDeleted = isDeleted;
}

/*
 * Function deleteEntity
 * ---------------------
 * Marks an Entity as deleted.
 */
void deleteEntity(Entity* ent) {
    ent->isDeleted = true;
}

/*
 * Function updateEntity
 * ---------------------
 * Updates the Entity position using the current velocity
 */
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

    x_overlap = dx < ((ent_a->w + ent_b->w) >> 1);
    y_overlap = dy < ((ent_a->h + ent_b->h) >> 1);

    if (x_overlap && y_overlap){
        set_led(0x03);
        return true;
    }
    else
        return false;
}

/*
 * Function detectBoundaryBox
 * --------------------------
 * Checks if an Entity is on, or outside a specified boundary box.
 *
 * ent:              pointer to entity being checked for boundary box collision
 * x1, y1, x2, y2:   boundary box dimensions
 *
 * returns:   an integer where bits 0-3 code for each side of the boundary.
 *            Each bit is 1 if the entity is exceeding that side of the boundary box.
 *            bit 0: x1, left side
 *            bit 1: x2, right side
 *            bit 2: y1, top side
 *            bit 3: y2, bottom side
 */
uint8_t detectBoundaryBox(Entity* ent, int32_t x1, int32_t y1, int32_t x2, int32_t y2) {
    uint8_t boundaryState = 0;

    if ((ent->x - ent->w / 2) <= (x1 << FIX_14_SHIFT)) {
        boundaryState |= 0x01 << 0;
    } else if ((ent->x + ent->w / 2) >= (x2 << FIX_14_SHIFT)) {
        boundaryState |= 0x01 << 1;
    }

    if ((ent->y - ent->h / 2) <= (y1 << FIX_14_SHIFT)) {
        boundaryState |= 0x01 << 2;
    } else if ((ent->y + ent->h / 2) >= (y2 << FIX_14_SHIFT)) {
        boundaryState |= 0x01 << 3;
    }

    return boundaryState;
}

void drawSprite(Entity* ent, const char sprite[]) {
    gotoxy(ent->x >> FIX_14_SHIFT, ent->y >> FIX_14_SHIFT);
    printf(sprite);
}
