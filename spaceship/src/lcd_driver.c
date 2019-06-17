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

    void lcdWriteString(char letter[], char *buffer, int16_t line, int16_t slice){



    int i,j;


//   memset(buffer, 0x00, 512);

    int length = strlen(letter);


    for(i = 0; i<length;i++){
            for(j=0; j<5; j++){


                    buffer[(i*5+j)] = character_data[letter[i] -0x20][j];
                    }
                    if(((i+1)*5)>127);
                    line++;



            }

    }
