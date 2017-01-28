/* 
 * File:   delay.h
 * Author: martin
 *
 * Created on January 26, 2017, 11:23 PM
 */

void delay100ms(int count)
{
    int i,j,k,l;
    for (i=0; i < count; i++) {
        for (j=0; j < 1; j++) {
            for (k=0; k < 250; k++) {
                 for (l=0; l < 250; l++) {
                }
            }
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