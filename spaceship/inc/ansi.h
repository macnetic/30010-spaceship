#include <stdint.h>
#include <stdio.h>

#ifndef _ANSI_H_

#define _ANSI_H_
void fgcolor(uint8_t foreground);
void bgcolor(uint8_t background);
void color(uint8_t foreground, uint8_t background);
void clrscr(void);
void clreol(void);
void gotoxy(uint8_t x, uint8_t y);
void underline(uint8_t on);
void blink(uint8_t on);
void inverse(uint8_t on);
void window(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, char* title, uint8_t style);

#endif /* _ANSI_H_ */
