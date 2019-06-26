#include <powerup.h>


const static char powerup_sprite[] = {H_BK, L_BK, H_BK, ESC, '[', '3', B_MV, ESC, '[', D_MV, H_BK, ESC, '[', F_MV, H_BK,'\0'};

const static char powerup_delete_sprite[] = {' ', ' ', ' ', ESC, '[', '3', B_MV, ESC, '[', D_MV, ' ', ESC, '[', F_MV, ' ','\0'};

void spawnPowerup(Powerup* powerup, uint32_t x, uint32_t y, uint8_t type, bool isDeleted) {
    spawnEntity(&powerup->entity, x, y, 0, 0, POWERUP_HITBOX_WIDTH, POWERUP_HITBOX_HEIGHT, isDeleted);

    powerup->type = type;
}

void drawPowerupSprite(Powerup* powerup) {
    switch (powerup->type) {
        case 0: fgcolor(4); break;
        case 1: fgcolor(2); break;

    }

    drawSprite(&powerup->entity, powerup_sprite);
}

void deletePowerupSprite(Powerup* powerup) {
    drawSprite(&powerup->entity, powerup_delete_sprite);
}
