#include <enemy.h>

const static char enemy_sprite[] = {L_BK, F_BK, F_BK, H_BK,ESC, '[','2', B_MV, ESC, '[',U_MV, L_BK, ESC, '[','2', D_MV, ESC, '[', '2', B_MV, H_BK, F_BK, H_BK, '\0'};

const static char enemy_delete_sprite[] = {' ', ' ', ' ', ' ',ESC, '[','2', B_MV, ESC, '[',U_MV, ' ', ESC, '[','2', D_MV, ESC, '[', '2', B_MV, ' ', ' ', ' ', '\0'};

void spawnEnemy(Enemy* enemy, uint32_t x, uint32_t y, uint32_t vx, uint32_t vy, uint32_t mass, int32_t hp, bool isDeleted) {
    spawnEntity(&enemy->entity, x, y, vx, vy, ENEMY_HITBOX_WIDTH, ENEMY_HITBOX_HEIGHT, isDeleted);

    enemy->mass = mass;
    enemy->hp = hp;
}

void drawEnemySprite(Enemy* enemy) {
    fgcolor(1);
    drawSprite(&enemy->entity, enemy_sprite);
}

void deleteEnemySprite(Enemy* enemy) {
    fgcolor(1);
    drawSprite(&enemy->entity, enemy_delete_sprite);
}
