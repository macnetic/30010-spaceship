#include <stdint.h>
#include <stdio.h>
#include "lcd_driver.h"
#include "trig_lut.h"
#include "30010_io.h"
#include "charset.h"
#define ESC 0x1B



void drawSpaceShip(int x, int y){



    gotoxy(x,y);

    printf("%c",44);
    printf("%c[D",ESC);
//    printf("%c[B",ESC);
//    printf("%c%c",44,44);



}

void drawAsteroid(){



}


