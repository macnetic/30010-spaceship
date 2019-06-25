#include "HUD.h"

static char buffer[512] = {0};

void updateHUD(Player * player){
    memset(buffer,0x00,512);

    uint8_t i;
    for(i = 0; i < (*player).hp; i++){
        lcdWriteSymbol(95,buffer,0,i*2);
        lcdWriteSymbol(96,buffer,0,i*2+1);
    }

    for(i = 0; i < (*player).ammo; i++){
        lcdWriteSymbol(97,buffer,2,i);
    }
    lcd_push_buffer(buffer);
}
