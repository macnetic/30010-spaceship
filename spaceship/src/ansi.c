#include "stdint.h"
#include "stdio.h"
#include "ansi.h"
#include "30010_io.h"
#include "lcd_driver.h"

#define ESC 0x1B

void fgcolor(uint8_t foreground) {
/*  Value      foreground     Value     foreground
    ------------------------------------------------
      0        Black            8       Dark Gray
      1        Red              9       Light Red
      2        Green           10       Light Green
      3        Brown           11       Yellow
      4        Blue            12       Light Blue
      5        Purple          13       Light Purple
      6        Cyan            14       Light Cyan
      7        Light Gray      15       White
*/
  uint8_t type = 22;             // normal text
	if (foreground > 7) {
	  type = 1;                // bold text
		foreground -= 8;
	}
  printf("%c[%d;%dm", ESC, type, foreground+30);
}

void bgcolor(uint8_t background) {
/* IMPORTANT:   When you first use this function you cannot get back to true white background in HyperTerminal.
   Why is that? Because ANSI does not support true white background (ANSI white is gray to most human eyes).
                The designers of HyperTerminal, however, preferred black text on white background, which is why
                the colors are initially like that, but when the background color is first changed there is no
 	              way comming back.
   Hint:        Use resetbgcolor(); clrscr(); to force HyperTerminal into gray text on black background.

    Value      Color
    ------------------
      0        Black
      1        Red
      2        Green
      3        Brown
      4        Blue
      5        Purple
      6        Cyan
      7        Gray
*/
  printf("%c[%dm", ESC, background+40);
}

void color(uint8_t foreground, uint8_t background) {
// combination of fgcolor() and bgcolor() - uses less bandwidth
  uint8_t type = 22;             // normal text
	if (foreground > 7) {
	  type = 1;                // bold text
		foreground -= 8;
	}
  printf("%c[%d;%d;%dm", ESC, type, foreground+30, background+40);
}

void resetbgcolor() {
// gray on black text, no underline, no blink, no reverse
  printf("%c[m", ESC);
}

void clrscr(void) {
    printf("%c[2J", ESC);
}

void clreol(void) {
    printf("%c[K", ESC);
}

void gotoxy(uint8_t x, uint8_t y) {
    printf("%c[%d;%dH", ESC, y, x);
}

void underline(uint8_t on) {
    if (on == 1)
        printf("%c[04m", ESC);
    else
        printf("%c[24m", ESC);
}

void blink(uint8_t on) {
    if (on == 1)
        printf("%c[05m", ESC);
    else
        printf("%c[25m", ESC);
}

void inverse(uint8_t on) {
    if (on == 1)
        printf("%c[07m", ESC);
    else
        printf("%c[27m", ESC);
}

void window(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, char* title, uint8_t style) {
    uint8_t border0[8] = {218, 192, 217, 191, 179, 196, 180, 195};
    uint8_t border1[8] = {201, 200, 188, 187, 186, 205, 185, 204};

    uint8_t *border;
    if (style == 0) border = border0;
    else border = border1;

    // swap values so (x1, y1) is top left corner
    if (x2-x1 < 0) {
        uint8_t temp = x1;
        x1 = x2;
        x2 = temp;
    }
    if (y2-y1 < 0) {
        uint8_t temp = y1;
        y1 = x2;
        y2 = temp;
    }

    uint8_t w = x2 - x1;
    uint8_t h = y2 - y1;

    // Top left corner
    gotoxy(x1, y1);
    printf("%c", border[0]);

    // Left side
    for (uint8_t i=0; i < h-2; i++) {
        printf("%c[1B", ESC);
        printf("%c[1D", ESC);
        printf("%c", border[4]);
    }

    // Bottom left corner
    printf("%c[1B", ESC);
    printf("%c[1D", ESC);
    printf("%c", border[1]);

    // Bottom side
    for (uint8_t i=0; i < w-2; i++) printf("%c", border[5]);

    // Bottom right corner
    printf("%c", border[2]);

    // Right side
    for (uint8_t i=0; i < h-2; i++) {
        printf("%c[1A", ESC);
        printf("%c[1D", ESC);
        printf("%c", border[4]);
    }

    // Top right corner
    printf("%c[1A", ESC);
    printf("%c[1D", ESC);
    printf("%c", border[3]);

    // Top side
    gotoxy(x1+1,y1);
    for (uint8_t i=0; i < w-2; i++) printf("%c", border[5]);

    // Put title on top of top side
    gotoxy(x1+2,y1);
    printf("%c", border[6]);
    inverse(1);
    printf("%s", title);
    inverse(0);
    printf("%c%c", border[7], border[5]);
}

/**
 * Reads n chars from UART and writes as string array to char array in argument
 */
void read_chars(char out[], uint32_t n) {
    uint32_t i = 0;
    uart_clear();

    while(i < n) {
        char next = uart_get_char();
        if (next != 0) {
            if (next == 0x0D) {
                break;

            }
            out[i] = next;
            i++;
        }
    }
    out[i] = '\0';
}

char getInput(void) {
    char out = 0;

    out = uart_get_char();
    uart_clear();

    return out;
}


