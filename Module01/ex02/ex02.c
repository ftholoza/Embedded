#include "ex02.h"

int	main(void)
{
    //PB1 output
	DDRB |= (1 << PB1);

	DDRB |= (1 << PB1);
	
	//COM1A1: active le contrôle du timer sur PB1 (PWM non-inversé)
	//WGM11, WGM13 et WGM12 pour activer le mode fast-PWM
	//CS12: prescaler+
	TCCR1A = (1 << COM1A1) | (1 << WGM11);
	TCCR1B = (1 << WGM13) | (1 << WGM12) | (1 << CS12);
	
	//ICR1: valeur limite
	//OCR1A: duty cycle declancheur d'evenement
	//TCNT1: valeur depart
	//16.000.000 / 256 = 62500
	//10% de 62500 = 6250
	ICR1 = 62499;
	OCR1A = 6249;
    TCNT1 = 0;

	while (1)
	{
	}
}
