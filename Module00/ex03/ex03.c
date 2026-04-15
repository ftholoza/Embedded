#include "ex03.h"

int main(void)
{
	int prev = 1;
	int curr;

	DDRB |= (1 << PB0);
	DDRD &= ~(1 << PD2);

	while (1)
	{
		curr = (PIND & (1 << PD2)) ? 1 : 0;

		if (prev == 1 && curr == 0)
		{
			PORTB ^= (1 << PB0);
			_delay_ms(50);
		}

		prev = curr;
	}
	return (0);
}