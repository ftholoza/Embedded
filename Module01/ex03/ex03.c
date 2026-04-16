#include "ex03.h"

void	changeDC(uint8_t duty)
{
	if (duty >= 100)
		OCR1A = ICR1;
	else
		OCR1A = ((ICR1 / 100) * duty);
}

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
	ICR1 = 62500 - 1;
	OCR1A = 6250 - 1;
    TCNT1 = 0;

	uint8_t currSW1;
	uint8_t currSW2;
	uint8_t prevSW1 = 1;
	uint8_t prevSW2 = 1;
	uint8_t duty = 10;

	while (1)
	{
		currSW1 = (PIND & (1 << PD2)) ? 1 : 0;
		currSW2 = (PIND & (1 << PD4)) ? 1 : 0;
		if (prevSW1 == 1 && currSW1 == 0)
		{
			if (duty < 100)
				duty +=10;
			changeDC(duty);
			while ((PIND & (1 << PD2)) == 0)
				;
			_delay_ms(50);

		}
		if (prevSW2 == 1 && currSW2 == 0)
		{
			if (duty > 0)
				duty -= 10;
			changeDC(duty);
			while ((PIND & (1 << PD4)) == 0)
				;
			_delay_ms(50);
		}
	}
}
