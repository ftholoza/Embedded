#include "ex01.h"

int main(void)
{
	// role de la pin: 0 = entree 1 = sortie
	// on met PB0 en mode sortie 
	DDRB |= (1 << PB0);

	// envoie le un signal
	// 1 = 5V et 0 = 0V
	// PB0 envoie 5V
	PORTB |= (1 << PB0);
    //PORTB |= (0b1111111);
}