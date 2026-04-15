#include "avr/io.h"

void    wait(void)
{
    volatile unsigned long i;
    for (i = 0; i < 235000; i++)
        ;
    return;

}

int main (void)
{

    DDRB |= (1 << PB1);
    while (1)
    {
        PORTB ^= (1 << PB1);
        wait();
    }
}