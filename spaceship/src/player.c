#include <player.h>
#include <spaceship.h>

const static char player_sprite[8][40] = {
    {   // North
        ESC, '[' ,'2', U_MV, L_BK, ESC, '[', D_MV, ESC, '[', B_MV, F_BK, ESC,  '[', D_MV, ESC,
        '[', '2', B_MV, F_BK, H_BK, F_BK, ESC, '[', '3', B_MV, ESC, '[', D_MV, H_BK, ESC,
        '[', F_MV, H_BK, '\0'
    },
    {   // Northwest
        ESC, '[' ,'2', B_MV, ESC, '[', U_MV, H_BK, L_BK, ESC, '[', F_MV, L_BK, ESC, '[', D_MV, ESC, '[', '3', B_MV,
        L_BK, F_BK, H_BK, H_BK, L_BK, ESC, '[', D_MV, ESC, '[', '4', B_MV, H_BK,
        L_BK, '\0'
    },
    {   // West
        ESC, '[' ,'3', B_MV, L_BK, L_BK, L_BK, F_BK, H_BK, H_BK, ESC, '[', '3', B_MV, ESC, '[', D_MV,
        H_BK, H_BK, H_BK, '\0'
    },
    {   // Southwest
        ESC, '[', U_MV, L_BK, H_BK, ESC, '[', D_MV, ESC, '[', '3', B_MV, H_BK, F_BK, L_BK, L_BK,
        H_BK, ESC, '[', D_MV, ESC, '[', '6', B_MV, L_BK, H_BK, ESC, '[', F_MV,
        H_BK, '\0'
    },
    {   // South
        ESC, '[' , B_MV, ESC, '[', U_MV, L_BK, ESC, '[', F_MV, L_BK, ESC, '[', D_MV, ESC, '[', '3', B_MV, F_BK,
        L_BK, F_BK, ESC, '[', D_MV, ESC, '[', '2', B_MV, F_BK, ESC, '[', D_MV, ESC, '[',
        B_MV, H_BK, '\0'
    },
    {   // Southeast
        ESC, '[', B_MV, ESC, '[', U_MV, H_BK, L_BK, ESC, '[', D_MV, ESC, '[', '4', B_MV, H_BK, L_BK, L_BK, F_BK,
        H_BK, ESC, '[', D_MV, ESC, '[', '3', B_MV, H_BK, ESC, '[' ,F_MV, H_BK,
        L_BK, '\0'
    },
    {   // East
        ESC, '[' ,'2', B_MV, H_BK, H_BK, F_BK, L_BK, L_BK, L_BK, ESC, '[', D_MV, ESC, '[', '6', B_MV,
        H_BK, H_BK, H_BK, '\0'
    },
    {   // Northeast
        ESC, '[', B_MV, ESC, '[', U_MV, L_BK, ESC, '[', 'C', L_BK, H_BK, ESC, '[', 'B', ESC, '[', '6', 'D',
        L_BK, H_BK, H_BK, F_BK, L_BK, ESC, '[', 'B', ESC, '[', '3', 'D', L_BK,
        H_BK, '\0'
    }
};

const static char player_delete_sprite[8][40] = {
    {   // North
        ESC, '[' ,'2', U_MV, ' ', ESC, '[', D_MV, ESC, '[', B_MV, ' ', ESC,  '[', D_MV, ESC,
        '[', '2', B_MV, ' ', ' ', ' ', ESC, '[', '3', B_MV, ESC, '[', D_MV, ' ', ESC,
        '[', F_MV, ' ', '\0'
    },
    {   // Northwest
        ESC, '[' ,'2', B_MV, ESC, '[', U_MV, ' ', ' ', ESC, '[', F_MV, ' ', ESC, '[', D_MV, ESC, '[', '3', B_MV,
        ' ', ' ', ' ', ' ', ' ', ESC, '[', D_MV, ESC, '[', '4', B_MV, ' ',
        ' ', '\0'
    },
    {   // West
        ESC, '[' ,'3', B_MV, ' ', ' ', ' ', ' ', ' ', ' ', ESC, '[', '3', B_MV, ESC, '[', D_MV,
        ' ', ' ', ' ', '\0'
    },
    {   // Southwest
        ESC, '[', U_MV, ' ', ' ', ESC, '[', D_MV, ESC, '[', '3', B_MV, ' ', ' ', ' ', ' ',
        ' ', ESC, '[', D_MV, ESC, '[', '6', B_MV, ' ', ' ', ESC, '[', F_MV,
        ' ', '\0'
    },
    {   // South
        ESC, '[' , B_MV, ESC, '[', U_MV, ' ', ESC, '[', F_MV, ' ', ESC, '[', D_MV, ESC, '[', '3', B_MV, ' ',
        ' ', ' ', ESC, '[', D_MV, ESC, '[', '2', B_MV, ' ', ESC, '[', D_MV, ESC, '[',
        B_MV, ' ', '\0'
    },
    {   // Southeast
        ESC, '[', B_MV, ESC, '[', U_MV, ' ', ' ', ESC, '[', D_MV, ESC, '[', '4', B_MV, ' ', ' ', ' ', ' ',
        ' ', ESC, '[', D_MV, ESC, '[', '3', B_MV, ' ', ESC, '[' ,F_MV, ' ',
        ' ', '\0'
    },
    {   // East
        ESC, '[' ,'2', B_MV, ' ', ' ', ' ', ' ', ' ', ' ', ESC, '[', D_MV, ESC, '[', '6', B_MV,
        ' ', ' ', ' ', '\0'
    },
    {   // Northeast
        ESC, '[', B_MV, ESC, '[', U_MV, ' ', ESC, '[', 'C', ' ', ' ', ESC, '[', 'B', ESC, '[', '6', 'D',
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
void spawnPlayer(Player* player, uint32_t x, uint32_t y, uint32_t mass, uint32_t ammo, uint32_t heading, int32_t hp, bool isDeleted) {
    spawnEntity(&player->entity, x, y, 0, 0, PLAYER_HITBOX_WIDTH, PLAYER_HITBOX_HEIGHT, isDeleted);

    player->mass = mass;
    player->ammo = ammo;
    player->heading = heading;
    player->hp = hp;
    player->triggerPressed = false;
}


//
//
//const static char bomb_sprite = {ESC, '[', '2', U_MV, ESC, '[', '2', B_MV, L_BK, F_BK, ESC, '[', F_MV, F_BK,L_BK, ESC, '[', '6', B_MV, ESC, '[', D_MV,
//                                 H_BK, H_BK, H_BK, L_BK, H_BK, H_BK, H_BK, ESC, '[', '6', B_MV, ESC, '[', D_MV,
//                                 L_BK, F_BK, F_BK, F_BK, L_BK, '\0'
//                                };


/*
 * Function controlPlayer
 * ----------------------
 * Read player control input from the user and updates player state accordingly.
 *
 * player:   Pointer to player being controlled
 */
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
        thrustPlayer(player);
    } else if (input == 'S' || input == 's') {
        // Brake
        brakePlayer(player);
    } else if (input == ' ') {
        // Set a flag to spawn a projectile shooting from this player
        player->triggerPressed = true;

    } else if(input == 0x1B){ // minimize window

        printf("%c[9;0t",ESC);
        clrscr();
    } else if (input == 0x0D){ // Maximize window and redraw window to continue playing
        printf("%c[9;1t",ESC);
        clrscr();
        fgcolor(15);
        window(1, 1, GAME_WINDOW_WIDTH, GAME_WINDOW_HEIGHT, "", 1);
    }
}

/*
 * Function thrustPlayer
 * ---------------------
 * Thrusts the player forward in the heading direction.
 *
 * player:   pointer to player instance
 */
void thrustPlayer(Player* player) {
    switch (player->heading) {
    case 0: player->entity.vy -= 1 << (FIX_14_SHIFT - PLAYER_VEL_SCALE); break;
    case 1: player->entity.vx -= 2 << (FIX_14_SHIFT - PLAYER_VEL_SCALE); player->entity.vy -= 1 << (FIX_14_SHIFT - PLAYER_VEL_SCALE); break;
    case 2: player->entity.vx -= 2 << (FIX_14_SHIFT - PLAYER_VEL_SCALE); break;
    case 3: player->entity.vx -= 2 << (FIX_14_SHIFT - PLAYER_VEL_SCALE); player->entity.vy += 1 << (FIX_14_SHIFT - PLAYER_VEL_SCALE); break;
    case 4: player->entity.vy += 1 << (FIX_14_SHIFT - PLAYER_VEL_SCALE); break;
    case 5: player->entity.vx += 2 << (FIX_14_SHIFT - PLAYER_VEL_SCALE); player->entity.vy += 1 << (FIX_14_SHIFT - PLAYER_VEL_SCALE); break;
    case 6: player->entity.vx += 2 << (FIX_14_SHIFT - PLAYER_VEL_SCALE); break;
    case 7: player->entity.vx += 2 << (FIX_14_SHIFT - PLAYER_VEL_SCALE); player->entity.vy -= 1 << (FIX_14_SHIFT - PLAYER_VEL_SCALE); break;
    }

    // Cap x velocity
    if (abs(player->entity.vx) > PLAYER_MAX_X_VEL << FIX_14_SHIFT) {
        if (player->entity.vx > 0)
            player->entity.vx = PLAYER_MAX_X_VEL << FIX_14_SHIFT;
        else
            player->entity.vx = -PLAYER_MAX_X_VEL << FIX_14_SHIFT;
    }

    // Cap y velocity
    if (abs(player->entity.vy) > PLAYER_MAX_Y_VEL << FIX_14_SHIFT) {
        if (player->entity.vy > 0)
            player->entity.vy = PLAYER_MAX_Y_VEL << FIX_14_SHIFT;
        else
            player->entity.vy = -PLAYER_MAX_Y_VEL << FIX_14_SHIFT;
    }
}

void brakePlayer(Player* player) {
    //x direction
    if(player->entity.vx > 0){
        player->entity.vx -= 2 << (FIX_14_SHIFT - PLAYER_VEL_SCALE);
    }else if(player->entity.vx < 0){
        player->entity.vx += 2 << (FIX_14_SHIFT - PLAYER_VEL_SCALE);
    }

    //y direction
    if(player->entity.vy > 0){
        player->entity.vy -= 1 << (FIX_14_SHIFT - PLAYER_VEL_SCALE);
    }else if(player->entity.vy < 0){
        player->entity.vy += 1 << (FIX_14_SHIFT - PLAYER_VEL_SCALE);
    }
}

/*
 * Function drawPlayerSprite
 * -------------------------
 * Draws the player spaceship in the game at the correct coordinates and with the correct heading.
 *
 * player:   pointer to the Player instance to be drawn
 */
void drawPlayerSprite(Player* player){
    fgcolor(2);
    drawSprite(&player->entity, player_sprite[player->heading]);
}

/*
 * Function deletePlayerSprite
 * ---------------------------
 * Overwrite the player sprite with spaces, to more efficiently redraw the game
 *
 * player:   pointer to the Player instance
 */
void deletePlayerSprite(Player* player){
    drawSprite(&player->entity, player_delete_sprite[player->heading]);
}

/*
 * Function keepPlayerInBounds
 * ---------------------------
 * Keeps the player inside the bounds specified.
 *
 * player:           pointer to Player being checked for boundary box collision
 * x1, y1, x2, y2:   boundary box dimensions
 */
void keepPlayerInBounds(Player* player, int32_t x1, int32_t y1, int32_t x2, int32_t y2) {
    uint8_t boundaryState = detectBoundaryBox(&player->entity, x1, y1, x2, y2);

    if ((boundaryState & (0x01 << 0)) > 0) {
        // Stop ship from exceeding left side
        player->entity.x = (player->entity.w / 2) + (x1 << FIX_14_SHIFT);
        player->entity.vx = 0;
    } else if ((boundaryState & (0x01 << 1)) > 0) {
        // Stop ship from exceeding right side
        player->entity.x = (x2 << FIX_14_SHIFT) - (player->entity.w / 2);
        player->entity.vx = 0;
    }

    if ((boundaryState & (0x01 << 2)) > 0) {
        // Stop ship from exceeding top side
        player->entity.y = (player->entity.h / 2) + (y1 << FIX_14_SHIFT);
        player->entity.vy = 0;
    } else if ((boundaryState & (0x01 << 3)) > 0) {
        // Stop ship from exceeding bottom side
        player->entity.y = ((y2 - 1) << FIX_14_SHIFT) - (player->entity.h / 2);
        player->entity.vy = 0;
    }
}
