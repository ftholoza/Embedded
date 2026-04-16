#include "ex01.h"

int	main(void)
{
    //PB1 output
	DDRB |= (1 << PB1);

    //toggle a chaque cycle
	TCCR1A = (1 << COM1A0);

	/*
	    Timer1 CTC mode = WGM12 a 1
        CTC mode = quand TCNT1 == OCR1A → TCNT1 est remis à 0
	    Prescaler a 256 = CS12 a 1
	*/
	TCCR1B = (1 << WGM12) | (1 << CS12);

    //pour la lisibilite
    TCNT1 = 0;


    /*
    OCR1A = fin du cycle timer
    16.000.000 / 256 = 62.500
      62.500 / 2 = 31250*/
	OCR1A = 31249;

	while (1)
	{
	}
}
