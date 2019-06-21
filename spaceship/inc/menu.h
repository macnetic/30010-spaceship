#include <stdint.h>
#include <stdio.h>
#include "lcd_driver.h"
#include "trig_lut.h"
#include "30010_io.h"
#include "charset.h"
#define ESC 0x1B
#include "ansi.h"

#ifndef _MENU_H_
#define _MENU_H_

//Screen navigation
char input[2];
void navigator(char buffer[]);

int8_t nextScreen;
/*
00: Main menu
02: Stage select
03: Help
*/

void invertLine(char buffer[], uint16_t line);
void addUnderline(char buffer[], uint16_t line);
void addRightArrow(char buffer[], uint8_t row, uint8_t col);

//Different menu screens
void screen_main(char buffer[]);
void screen_help(char buffer[]);
void screen_stageSelect(char buffer[]);

#endif
