#include "ex04.h"

void display_binary(uint8_t value)
{
	PORTB &= ~((1 << PB0) | (1 << PB1) | (1 << PB2) | (1 << PB4));

	if (value & (1 << 0))
		PORTB ^= (1 << PB0);
	if (value & (1 << 1))
		PORTB ^= (1 << PB1);
	if (value & (1 << 2))
		PORTB ^= (1 << PB2);
	if (value & (1 << 3))
		PORTB ^= (1 << PB4);
}

int main(void)
{
	uint8_t prevSW1 = 1;
	uint8_t currSW1;
	uint8_t prevSW2 = 1;
	uint8_t currSW2; 

	DDRB |= (1 << PB0) | (1 << PB1) | (1 << PB2) | (1 << PB4);
	DDRD &= ~(1 << PD2);
	DDRD &= ~(1 << PD4);
	uint8_t value = 0;


	while (1)
	{
		currSW1 = (PIND & (1 << PD2)) ? 1 : 0;
		currSW2 = (PIND & (1 << PD4)) ? 1 : 0;


		if (prevSW1 == 1 && currSW1 == 0)
		{
			value++;
			value &= 0x0F;
			display_binary(value);
			_delay_ms(50);
		}
		if (prevSW2 == 1 && currSW2 == 0)
		{
			value &= 0x0F;
			value--;
			display_binary(value);
			_delay_ms(50);
		}
		prevSW1 = currSW1;
		prevSW2 = currSW2;
	}
	return (0);
}