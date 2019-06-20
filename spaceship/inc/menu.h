#include <stdint.h>
#include <stdio.h>
#include "lcd_driver.h"
#include "trig_lut.h"
#include "30010_io.h"
#include "charset.h"
#define ESC 0x1B

int8_t currentScreen;//TODO
int8_t currentOption;//TODO

void invertLine(char buffer[], uint16_t line);
void addUnderline(char buffer[], uint16_t line);
void navigateMenu();//TODO
void addRightArrow(char buffer[], uint8_t row, uint8_t col);

//Different menu screens
void screen_main(char buffer[]);//TODO
void screen_help(char buffer[]);//TODO
void screen_stageSelect(char buffer[]);//TODO
