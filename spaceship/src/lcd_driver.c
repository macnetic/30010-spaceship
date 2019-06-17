#include <stdint.h>
#include <stdio.h>
#include "lcd_driver.h"
#include "trig_lut.h"
#include "30010_io.h"
#include "charset.h"
#define ESC 0x1B

uint8_t LCDsetup(uint8_t buffer){



    lcd_init();

    //lcd_reset();

    //lcd_transmit_byte();// only if you know what you are doing



    memset(buffer, 0x80, 512);

    lcd_push_buffer(buffer); //updates display


    }


void lcdWriteString(char str[], char *buffer, int16_t row, int16_t col) {
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
