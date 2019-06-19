#include <stdint.h>
#include <stdio.h>
#include "lcd_driver.h"
#include "trig_lut.h"
#include "30010_io.h"
#include "charset.h"
#include <wchar.h>
#include <locale.h>

#define ESC 0x1B



void drawSpaceShip(uint32_t x, uint32_t y){



    fgcolor(2);

    int lowsmall = 220;
    int highsmall = 223;
    int bigSquare = 219;
    // C moves forward A moves up D moves back B moves down

    gotoxy(10,10);


    //Pointing 90

    char N[] = {lowsmall,ESC,'[','D',ESC,'[','B',bigSquare,ESC,'[','2','D',ESC,'[','B',
                bigSquare,highsmall,bigSquare, ESC,'[','3','D',ESC,'[','B',highsmall,ESC,'[','C', highsmall,'\0'

    };

    printf(N);


    char NW[] = {highsmall,lowsmall,ESC,'[','C',lowsmall,
                 ESC, '[','B',ESC,'[','3','D',
                 lowsmall,bigSquare,highsmall,highsmall,lowsmall,
                 ESC,'[','B',ESC,'[','4','D',
                 highsmall,lowsmall,'\0'
                 };
    printf(NW);


    gotoxy(40,20);

    char W[] = {lowsmall,lowsmall,bigSquare,highsmall,highsmall,ESC,
                    '[','3','D',ESC,'[','B',highsmall,highsmall,highsmall, '\0'
                    };



    printf(W);
   //pointing 0

   char SE[] = {};

    gotoxy(20,20);


        char E[] = {highsmall,highsmall,bigSquare,lowsmall,lowsmall,lowsmall,ESC,
                    '[','6','D',ESC,'[','B',highsmall,highsmall,highsmall, '\0'
                    };

//        printf("%c%c%c%c%c%c",highsmall,highsmall,bigSquare,lowsmall,lowsmall,lowsmall);
//        printf("%c[B%c[6D",ESC,ESC);
//        printf("%c%c%c",highsmall,highsmall,highsmall);
//


    printf(E);

    //point 45

    gotoxy(30,30);


















//    printf("%c%c",44,44);



}

void drawAsteroid(int x, int y){

    fgcolor(1);

    gotoxy(x,y);

    int bigSquare = 219;
    int lowsmall = 220;
    int highsmall = 223;

    printf("%c[2A%c",ESC,lowsmall);
    printf("%c[B%c[3D%c%c%c%c%c",ESC,ESC,lowsmall,bigSquare,bigSquare,bigSquare,lowsmall);
    printf("%c[B%c[6D%c%c%c%c%c%c%c",ESC, ESC,bigSquare,bigSquare,bigSquare,bigSquare,bigSquare,bigSquare,bigSquare);
    printf("%c[B%c[6D",ESC,ESC);
    printf("%c%c%c%c%c",highsmall,bigSquare,bigSquare,bigSquare,highsmall);
    printf("%c[B%c[3D%c",ESC,ESC,highsmall);





}


