/* 
 * File:   delay.h
 * Author: martin
 *
 * Created on January 26, 2017, 11:23 PM
 */

void delay100ms(int count)
{
    int i,j,k;
    for (k=0; k < count; k++) {
        for (i=0; i< 164 * RATIO; i++) {
            for(j=0; j< 100; j++) {}
        }
    }    
}

void delaySec(int count)
{
    int i;
    for (i=0; i< count; i++) {
       delay100ms(10);
    }    
}