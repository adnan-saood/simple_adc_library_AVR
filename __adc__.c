#include <__adc__.h>

void _adc_init(void)
{
	ADMUX = (1 << REFS0); // AVCC
	//ADMUX |= (1 << REFS0) | (1 << REFS1); //1v1
	
	ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0) | (1 << ADEN); // Turn ADC On sample: 16M/128 = 125KHz
	ADMUX |= (0 << ADLAR);
	//ADMUX |= (1 << ADLAR); 8 bit
}

int _adc_read(uint8_t channel)
{
	ADMUX |= channel & 0x0f;
	ADCSRA |= (1 << ADSC);
	while(ADCSRA & (1 << ADSC));
	return ADCW;
}
