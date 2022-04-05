#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

unsigned int display_cursor;

int putmsg(unsigned char *r5){
        unsigned char ch, *r1;
        bool error = false;
        
        clear_display();
        display_cursor = 0;

        r1 = r5;
        r1 --;

        do{
                ch = *r1;
                error = putchar(ch);
                r1 ++;
        } while(ch != '\0' && !error);

        if (error)
                return 1;
        
        else 
                return 0;
}