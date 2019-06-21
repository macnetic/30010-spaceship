#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <trig_lut.h>
#include <30010_io.h>
#include <charset.h>


#ifndef _LCD_H_
#define _LCD_H_

void LCDsetup(char buffer[]);
void lcdWriteString(char letter[], char buffer[], int16_t row, int16_t col);
void lcdWriteSymbol(uint8_t symbol, char buffer[], int16_t row, int16_t col);

void invertLine(char buffer[], uint16_t line);
void addUnderline(char buffer[], uint16_t line);
void addRightArrow(char buffer[], uint8_t row, uint8_t col);

#endif /* _LCD_H_*/
