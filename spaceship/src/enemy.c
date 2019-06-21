#include <enemy.h>

void spawnEnemy(Enemy* enemy, uint32_t x, uint32_t y, uint32_t mass, int32_t hp) {
    spawnEntity(&enemy->entity, x, y, 0, 0, ENEMY_HITBOX_WIDTH, ENEMY_HITBOX_HEIGHT);

    enemy->mass = mass;
    enemy->hp = hp;
}
