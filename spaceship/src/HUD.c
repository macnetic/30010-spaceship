#include "HUD.h"

static char buffer[512] = {0};

void updateHUD(Player * player){
    char heart[3] = {0x5f + 0x20, 0x60 + 0x20, 0x5f + 0x20, 0x60 + 0x20, 0x5f + 0x20, 0x60 + 0x20, '\0'};
    lcdWriteString(heart, buffer, 0, 0);

    uint8_t i;
    for(i = 0; i < (*player).ammo; i++){
        lcdWriteSymbol(97,buffer,3,i);
    }
    lcd_push_buffer(buffer);
}
