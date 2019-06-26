#include "HUD.h"

static char buffer[512] = {0};

void updateHUD(Player * player){
    //Remove old drawings
    memset(buffer,0x00,512);

    uint8_t i;
    //How many lives the player has left
    for(i = 0; i < (*player).hp; i++){
        lcdWriteSymbol(95,buffer,0,i*2);
        lcdWriteSymbol(96,buffer,0,i*2+1);
    }

    //How much ammo the player has left
    for(i = 0; i < player->ammo; i++){
        lcdWriteSymbol(97,buffer,1,i);
    }

    //Show score
    char score_str[13];
    sprintf(score_str, "Score: %-5lu", player->score);
    lcdWriteString(score_str,buffer,2,0);

    //Update display
    lcd_push_buffer(buffer);
}
