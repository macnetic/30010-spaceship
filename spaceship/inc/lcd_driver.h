#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <trig_lut.h>
#include <30010_io.h>
#include <charset.h>


#ifndef _LCD_H_
#define _LCD_H_

void LCDsetup(char buffer[]);
void lcdWriteString(char letter[], char buffer[], int16_t line, int16_t slice);

#endif /* _LCD_H_*/
