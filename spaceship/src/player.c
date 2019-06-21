#include <player.h>

const static char player_sprite[8][32] = {
    {   // North
        L_BK, ESC, '[', D_MV, ESC, '[', B_MV, F_BK, ESC,  '[',  '2', D_MV, ESC,
        '[',  B_MV, F_BK, H_BK, F_BK, '[', '3', D_MV, ESC, '[', B_MV, H_BK, ESC,
        '[', F_MV, H_BK, '\0'
    },
    {   // Northwest
        H_BK, L_BK, ESC, '[', F_MV, L_BK, ESC, '[', D_MV, ESC, '[', '3', B_MV,
        L_BK, F_BK, H_BK, H_BK, L_BK, ESC, '[', D_MV, ESC, '[', '4', B_MV, H_BK,
        L_BK, '\0'
    },
    {   // West
        L_BK, L_BK, L_BK, F_BK, H_BK, H_BK, ESC, '[', '3', B_MV, ESC, '[', D_MV,
        H_BK, H_BK, H_BK, '\0'
    },
    {   // Southwest
        L_BK, H_BK, ESC, '[', D_MV, ESC, '[', '3', B_MV, H_BK, F_BK, L_BK, L_BK,
        H_BK, ESC, '[', D_MV, ESC, '[', '6', B_MV, L_BK, H_BK, ESC, '[', F_MV,
        H_BK, '\0'
    },
    {   // South
        L_BK, ESC, '[', F_MV, L_BK, ESC, '[', D_MV, ESC, '[', '3', B_MV, F_BK,
        L_BK, F_BK, '[', D_MV, ESC, '[', '2', B_MV, F_BK, '[', D_MV, ESC, '[',
        B_MV, H_BK, '\0'
    },
    {   // Southeast
        H_BK, L_BK, ESC, '[', D_MV, ESC, '[', '4', B_MV, H_BK, L_BK, L_BK, F_BK,
        H_BK, ESC, '[', D_MV, ESC, '[', '3', B_MV, H_BK, ESC, '[' ,F_MV, H_BK,
        L_BK, '\0'
    },
    {   // East
        H_BK, H_BK, F_BK, L_BK, L_BK, L_BK, ESC, '[', D_MV, ESC, '[', '6', B_MV,
        H_BK, H_BK, H_BK, '\0'
    },
    {   // Northeast
        L_BK, ESC, '[', 'C', L_BK, H_BK, ESC, '[', 'B', ESC, '[', '6', 'D',
        L_BK, H_BK, H_BK, F_BK, L_BK, ESC, '[', 'B', ESC, '[', '3', 'D', L_BK,
        H_BK, '\0'
    }
};

/*
 * Function: spawnEntity
 * ---------------------
 * Spawn a Player in the game.
 *
 * player:   pointer to Player struct
 * x, y:     position of player spacecraft
 * hp:       current number of hitpoints left for player
 * mass:     mass of player spacecraft
 * ammo:     current number of projectiles left
 */
void spawnPlayer(Player* player, uint32_t x, uint32_t y, uint32_t mass, uint32_t ammo, uint32_t heading, int32_t hp) {
    spawnEntity(&player->entity, x, y, 0, 0, PLAYER_HITBOX_WIDTH, PLAYER_HITBOX_HEIGHT);

    player->mass = mass;
    player->ammo = ammo;
    player->heading = heading;
    player->hp = hp;
}

/*
 * Function drawPlayer
 * -------------------
 * Draws the player spaceship in the game at the correct coordinates and with the correct heading.
 *
 * player:   pointer to the Player instance to be drawn
 */
void drawPlayer(Player* player){
    fgcolor(2);

    gotoxy(player->entity.x >> FIX_14_SHIFT, player->entity.y >> FIX_14_SHIFT);
    printf(player_sprite[player->heading]);
}

/*
 * Function getPlayerSprite
 * ------------------------
 * gets the correct player "sprite"
 *
 * player:   pointer to the Player instance to be drawn
 * out:      char array for writing sprite to
 */
void getPlayerSprite(Player* player, char out[]) {
    out = player_sprite[player->heading];
}
