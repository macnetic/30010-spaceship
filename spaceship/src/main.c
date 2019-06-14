/*
**
**                           Main.c
**
**
**********************************************************************/
/*
   Last committed:     $Revision: 00 $
   Last changed by:    $Author: $
   Last changed date:  $Date:  $
   ID:                 $Id:  $

**********************************************************************/
#include "stm32f30x_conf.h"
#include "30010_io.h"
#include "ansi.h"

int main(void)
{
    uint16_t length = 1;
    char out[length+1];

    uart_init(9600);
    clrscr();
    gotoxy(1,1);

    while(1){
    read_chars(out, length);
    printf("%s", out);
//    for (int i = 0; i <= length; i++)
//        printf("%02x ", out[i]);
    }
}
