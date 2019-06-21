#include <player.h>

const static char player_sprite[8][40] = {
    {   // North
        ESC, '[' ,'3', B_MV, ESC, '[' ,'2', U_MV, L_BK, ESC, '[', D_MV, ESC, '[', B_MV, F_BK, ESC,  '[', D_MV, ESC,
        '[', '2', B_MV, F_BK, H_BK, F_BK, ESC, '[', '3', B_MV, ESC, '[', D_MV, H_BK, ESC,
        '[', F_MV, H_BK, '\0'
    },
    {   // Northwest
        ESC, '[' ,'3', B_MV, ESC, '[' ,'2', U_MV, H_BK, L_BK, ESC, '[', F_MV, L_BK, ESC, '[', D_MV, ESC, '[', '3', B_MV,
        L_BK, F_BK, H_BK, H_BK, L_BK, ESC, '[', D_MV, ESC, '[', '4', B_MV, H_BK,
        L_BK, '\0'
    },
    {   // West
        ESC, '[' ,'3', B_MV, ESC, '[' ,'2', U_MV, L_BK, L_BK, L_BK, F_BK, H_BK, H_BK, ESC, '[', '3', B_MV, ESC, '[', D_MV,
        H_BK, H_BK, H_BK, '\0'
    },
    {   // Southwest
        ESC, '[' ,'3', B_MV, ESC, '[' ,'2', U_MV, L_BK, H_BK, ESC, '[', D_MV, ESC, '[', '3', B_MV, H_BK, F_BK, L_BK, L_BK,
        H_BK, ESC, '[', D_MV, ESC, '[', '6', B_MV, L_BK, H_BK, ESC, '[', F_MV,
        H_BK, '\0'
    },
    {   // South
        ESC, '[' ,'3', B_MV, ESC, '[' ,'2', U_MV, L_BK, ESC, '[', F_MV, L_BK, ESC, '[', D_MV, ESC, '[', '3', B_MV, F_BK,
        L_BK, F_BK, ESC, '[', D_MV, ESC, '[', '2', B_MV, F_BK, ESC, '[', D_MV, ESC, '[',
        B_MV, H_BK, '\0'
    },
    {   // Southeast
        ESC, '[' ,'3', B_MV, ESC, '[' ,'2', U_MV, H_BK, L_BK, ESC, '[', D_MV, ESC, '[', '4', B_MV, H_BK, L_BK, L_BK, F_BK,
        H_BK, ESC, '[', D_MV, ESC, '[', '3', B_MV, H_BK, ESC, '[' ,F_MV, H_BK,
        L_BK, '\0'
    },
    {   // East
        ESC, '[' ,'3', B_MV, ESC, '[' ,'2', U_MV, H_BK, H_BK, F_BK, L_BK, L_BK, L_BK, ESC, '[', D_MV, ESC, '[', '6', B_MV,
        H_BK, H_BK, H_BK, '\0'
    },
    {   // Northeast
        ESC, '[' ,'3', B_MV, ESC, '[' ,'2', U_MV, L_BK, ESC, '[', 'C', L_BK, H_BK, ESC, '[', 'B', ESC, '[', '6', 'D',
        L_BK, H_BK, H_BK, F_BK, L_BK, ESC, '[', 'B', ESC, '[', '3', 'D', L_BK,
        H_BK, '\0'
    }
};

const static char player_delete_sprite[8][40] = {
    {   // North
        ESC, '[' ,'3', B_MV, ESC, '[' ,'2', U_MV, ' ', ESC, '[', D_MV, ESC, '[', B_MV, ' ', ESC,  '[', D_MV, ESC,
        '[', '2', B_MV, ' ', ' ', ' ', ESC, '[', '3', B_MV, ESC, '[', D_MV, ' ', ESC,
        '[', F_MV, ' ', '\0'
    },
    {   // Northwest
        ESC, '[' ,'3', B_MV, ESC, '[' ,'2', U_MV, ' ', ' ', ESC, '[', F_MV, ' ', ESC, '[', D_MV, ESC, '[', '3', B_MV,
        ' ', ' ', ' ', ' ', ' ', ESC, '[', D_MV, ESC, '[', '4', B_MV, ' ',
        ' ', '\0'
    },
    {   // West
        ESC, '[' ,'3', B_MV, ESC, '[' ,'2', U_MV, ' ', ' ', ' ', ' ', ' ', ' ', ESC, '[', '3', B_MV, ESC, '[', D_MV,
        ' ', ' ', ' ', '\0'
    },
    {   // Southwest
        ESC, '[' ,'3', B_MV, ESC, '[' ,'2', U_MV, ' ', ' ', ESC, '[', D_MV, ESC, '[', '3', B_MV, ' ', ' ', ' ', ' ',
        ' ', ESC, '[', D_MV, ESC, '[', '6', B_MV, ' ', ' ', ESC, '[', F_MV,
        ' ', '\0'
    },
    {   // South
        ESC, '[' ,'3', B_MV, ESC, '[' ,'2', U_MV, ' ', ESC, '[', F_MV, ' ', ESC, '[', D_MV, ESC, '[', '3', B_MV, ' ',
        ' ', ' ', ESC, '[', D_MV, ESC, '[', '2', B_MV, ' ', ESC, '[', D_MV, ESC, '[',
        B_MV, ' ', '\0'
    },
    {   // Southeast
        ESC, '[' ,'3', B_MV, ESC, '[' ,'2', U_MV, ' ', ' ', ESC, '[', D_MV, ESC, '[', '4', B_MV, ' ', ' ', ' ', ' ',
        ' ', ESC, '[', D_MV, ESC, '[', '3', B_MV, ' ', ESC, '[' ,F_MV, ' ',
        ' ', '\0'
    },
    {   // East
        ESC, '[' ,'3', B_MV, ESC, '[' ,'2', U_MV, ' ', ' ', ' ', ' ', ' ', ' ', ESC, '[', D_MV, ESC, '[', '6', B_MV,
        ' ', ' ', ' ', '\0'
    },
    {   // Northeast
        ESC, '[' ,'3', B_MV, ESC, '[' ,'2', U_MV, ' ', ESC, '[', 'C', ' ', ' ', ESC, '[', 'B', ESC, '[', '6', 'D',
        ' ', ' ', ' ', ' ', ' ', ESC, '[', 'B', ESC, '[', '3', 'D', ' ',
        ' ', '\0'
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

void controlPlayer(Player* player) {
    char input = getInput();

    if (input == 'A' || input == 'a') {
        // Turn counterclockwise
        player->heading = (player->heading + 1) % 8;
    } else if (input == 'D' || input == 'd') {
        // Turn clockwise
        player->heading = (player->heading - 1) % 8;
    } else if (input == 'W' || input == 'w') {
        // Thrust forward
        switch (player->heading) {
            case 0: player->entity.y -= 1 << FIX_14_SHIFT; break;
            case 1: player->entity.x -= 2 << FIX_14_SHIFT; player->entity.y -= 1 << FIX_14_SHIFT; break;
            case 2: player->entity.x -= 2 << FIX_14_SHIFT; break;
            case 3: player->entity.x -= 2 << FIX_14_SHIFT; player->entity.y += 1 << FIX_14_SHIFT; break;
            case 4: player->entity.y += 1 << FIX_14_SHIFT; break;
            case 5: player->entity.x += 2 << FIX_14_SHIFT; player->entity.y += 1 << FIX_14_SHIFT; break;
            case 6: player->entity.x += 2 << FIX_14_SHIFT; break;
            case 7: player->entity.x += 2 << FIX_14_SHIFT; player->entity.y -= 1 << FIX_14_SHIFT; break;
        }

        // Keep player inside game window boundaries
//        if (player->entity.x + )
    }
}

/*
 * Function drawPlayer
 * -------------------
 * Draws the player spaceship in the game at the correct coordinates and with the correct heading.
 *
 * player:   pointer to the Player instance to be drawn
 */
void drawPlayerSprite(Player* player){
    fgcolor(2);

    gotoxy(player->entity.x >> FIX_14_SHIFT, player->entity.y >> FIX_14_SHIFT);
    printf(player_sprite[player->heading]);
}

void deletePlayerSprite(Player* player){
    fgcolor(2);

    gotoxy(player->entity.x >> FIX_14_SHIFT, player->entity.y >> FIX_14_SHIFT);
    printf(player_delete_sprite[player->heading]);
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
