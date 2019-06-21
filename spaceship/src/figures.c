#include <stdint.h>
#include <stdio.h>
#include "lcd_driver.h"
#include "ansi.h"
#include "trig_lut.h"
#include "30010_io.h"
#include "charset.h"
#include <wchar.h>
#include <locale.h>

#define lowsmall 220
#define highsmall 223
#define bigSquare 219

#define ESC 0x1B

const static int heading;

const static char N[] = {lowsmall,ESC,'[','D',ESC,'[','B',bigSquare,ESC,'[','2','D',ESC,'[','B',
                bigSquare,highsmall,bigSquare, ESC,'[','3','D',ESC,'[','B',highsmall,ESC,'[','C', highsmall,'\0'

    };
const static char NW[] = {highsmall,lowsmall,ESC,'[','C',lowsmall,
                 ESC, '[','B',ESC,'[','3','D',
                 lowsmall,bigSquare,highsmall,highsmall,lowsmall,
                 ESC,'[','B',ESC,'[','4','D',
                 highsmall,lowsmall,'\0'
                 };

const static char W[] = {lowsmall,lowsmall,lowsmall,bigSquare,highsmall,highsmall,ESC,
                    '[','3','D',ESC,'[','B',highsmall,highsmall,highsmall, '\0'
                    };

const static char SW[] = {lowsmall,highsmall,ESC,'[','B',ESC,'[','3','D',highsmall,bigSquare,lowsmall,lowsmall,highsmall,
                ESC,'[','B',ESC,'[','6','D',lowsmall,highsmall,ESC,'[','C', highsmall,'\0'
                };

const static char S[] = {lowsmall,ESC,'[','C',lowsmall,ESC,'[','B',ESC,'[','3','D',
                bigSquare,lowsmall,bigSquare,ESC,'[','B',ESC,'[','2','D',
                bigSquare,ESC,'[','B',ESC,'[','D',highsmall,'\0'
                };

const static  char SE[] = {highsmall,lowsmall,ESC,'[','B',ESC,'[','4','D',
                 highsmall,lowsmall,lowsmall,bigSquare,highsmall,
                 ESC,'[','B',ESC,'[','3','D',
                 highsmall,ESC,'[','C',highsmall,lowsmall,'\0'
                };
const static char E[] = {highsmall,highsmall,bigSquare,lowsmall,lowsmall,lowsmall,ESC,
                    '[','6','D',ESC,'[','B',highsmall,highsmall,highsmall, '\0'
                    };

const static  char NE[] = {lowsmall,ESC,'[','C',lowsmall,highsmall,ESC,'[','B',ESC,'[','6','D',
                lowsmall,highsmall,highsmall,bigSquare,lowsmall,ESC,'[','B',ESC,'[','3','D',
                lowsmall,highsmall,'\0'
                };


//void drawPlayer(Player* player){
//    fgcolor(2);
//
//    // C moves forward A moves up D moves back B moves down
//
//    gotoxy(x, y);
//    switch (player->heading) {
//        case 0: printf(N); break;
//        case 1: printf(NW); break;
//        case 2: printf(W); break;
//        case 3: printf(SW); break;
//        case 4: printf(S); break;
//        case 5: printf(SE); break;
//        case 6: printf(E); break;
//        case 7: printf(NE); break;
//    }
//
////    printf("%c%c",44,44);
//}

void drawAsteroid(int x, int y){

    fgcolor(1);

    gotoxy(x,y);

    printf("%c[2A%c",ESC,lowsmall);
    printf("%c[B%c[3D%c%c%c%c%c",ESC,ESC,lowsmall,bigSquare,bigSquare,bigSquare,lowsmall);
    printf("%c[B%c[6D%c%c%c%c%c%c%c",ESC, ESC,bigSquare,bigSquare,bigSquare,bigSquare,bigSquare,bigSquare,bigSquare);
    printf("%c[B%c[6D",ESC,ESC);
    printf("%c%c%c%c%c",highsmall,bigSquare,bigSquare,bigSquare,highsmall);
    printf("%c[B%c[3D%c",ESC,ESC,highsmall);





}

uint8_t rotateSpaceship(uint8_t x, uint8_t y, uint8_t heading){
    uint16_t length = 1;
    char out[length+1];
    char next;

    read_chars(out,length);
    next = out[0];
    if ((next == 'A') || (next == 'a')) {
            return 1;
    }
    else if((next == 'D') || (next == 'd')){

            return -1;
    }
    else if((next == 'W') || (next=='w')){

       switch (heading) {
            case 0: y--; break;
            case 1: {y--; x--;} break;
            case 2: {x--; break;}
            case 3: {y++; x--; break;}
            case 4: {y++; break;}
            case 5: {y++; x++; break;}
            case 6: {x++; break;}
            case 7: {y--; x++; break;}
        }
        return 0;
    }
    else return 0;
}

void thrust(){



}
