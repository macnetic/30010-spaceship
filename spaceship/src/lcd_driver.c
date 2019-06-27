#include "lcd_driver.h"



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


