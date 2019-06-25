#include "HUD.h"

static char buffer[512] = {0};

void updateHUD(Player * player){
    uint8_t i;
    //Show how much HP player has left
    for(i = 0; i < (*player).hp; i++){
        lcdWriteSymbol(95,buffer,0,i*2);
        lcdWriteSymbol(96,buffer,0,i*2+1);
    }

    //Show how much ammo player has left
    for(i = 0; i < (*player).ammo; i++){
        lcdWriteSymbol(97,buffer,2,i);
    }
    lcd_push_buffer(buffer);
}
