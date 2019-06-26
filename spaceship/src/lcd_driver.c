#include "lcd_driver.h"

//void LCDsetup(char buffer[]){
//    lcd_init();
//
//
//    memset(buffer, 0x80, 512);
//
//    lcd_push_buffer((uint8_t*) buffer); //updates display
//    }


void lcdWriteString(char str[], char buffer[], int16_t row, int16_t col) {
	uint16_t i, j, k, len;

	len = strlen(str);

	// Index characters in string
	for (i=0; i < len; i++) {
		// Index pixel columns in character
		for (j=0; j<5; j++) {
			k = (i + col) * 5 + 128 * row + j;
			buffer[k] = character_data[str[i] - 0x20][j];
		}
	}
}

void lcdWriteSymbol(uint8_t symbol, char buffer[], int16_t row, int16_t col) {
	uint16_t i, j;
		// Index pixel columns in character
    for (i=0; i<5; i++) {
        j = col * 5 + 128 * row + i;
        buffer[j] = character_data[symbol][i];
    }
}

void invertLine(char buffer[], uint16_t line){
    uint16_t i;
    for(i = 128*line; i < 128*(line+1); i++){
        buffer[i] ^= 0x7F;
    }
}

void addUnderline(char buffer[], uint16_t line){
    uint16_t i;
    for(i = 128*line; i < 128*(line+1); i++){
        buffer[i] |= 0x80;
    }
}

void addRightArrow(char buffer[], uint8_t row, uint8_t col){
    uint16_t pos = col + 128*row;
    buffer[pos]   = 0xFE;
    buffer[pos+1] = 0x7C;
    buffer[pos+2] = 0x38;
    buffer[pos+3] = 0x10;
}
