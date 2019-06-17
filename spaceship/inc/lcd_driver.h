#include <stdint.h>
#include <stdio.h>
#include "30010_io.h"
#ifndef _ANSI_H_
#define _ANSI_H_

uint8_t LCDsetup(uint8_t buffer);
void lcdWriteString(char letter[], char *buffer, int16_t line, int16_t slice);




#endif /* _ANSI_H_*/