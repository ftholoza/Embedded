#include "ex02.h"

int main(void)
{

	//set PB0 sur output et PD2 sur input
	DDRB |= (1 << PB0);
	DDRD &= ~(1 << PD2);

	while (1)
	{
		if (!(PIND & (1 << PD2)))
		{
			PORTB |= (1 << PB0);
		}
		else
		{
			PORTB &= ~(1 << PB0);
		}
	}
	return (0);
}