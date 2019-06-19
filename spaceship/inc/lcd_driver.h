#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <trig_lut.h>
#include <30010_io.h>
#include <charset.h>


#ifndef _ANSI_H_
#define _ANSI_H_

#define ESC 0x1B

uint8_t LCDsetup(uint8_t buffer);
void lcdWriteString(char letter[], char *buffer, int16_t line, int16_t slice);

#endif /* _ANSI_H_*/
