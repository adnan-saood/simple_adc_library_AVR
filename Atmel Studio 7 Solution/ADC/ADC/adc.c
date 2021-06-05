/*
 * ADC.c
 *
 * Created: 6/5/2021 3:32:32 AM
 * Author : Adnan Saood (adnan.saood@outlook.com)
 */ 

#include <avr/io.h>

#include "adc.h"

static int res = 0;

void adcInit(uint8_t Aref, uint8_t resolution)
{
	
	res = resolution;
	ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0) | (1 << ADEN); /// Turn ADC On sample: 16M/128 = 125KHz
	if(Aref == _Aref_1v1)
	{
		ADMUX |= (1 << REFS0) | (1 << REFS1); 
	}
	else if(Aref == _Aref_VCC)
	{
		ADMUX = (1 << REFS0); 
	}
	if(resolution == _ADC_RES_10)
	{
		ADMUX |= (0 << ADLAR);
	}
	else if (resolution == _ADC_RES_8)
	{
		ADMUX |= (1 << ADLAR);
	} 
}

uint16_t adcRead(uint8_t channel)
{
	ADMUX |= channel & 0x0f;
	ADCSRA |= (1 << ADSC);
	while(ADCSRA & (1 << ADSC));
	if(res == _ADC_RES_10)
	{
		return ADCW;
	}
	else if(res == _ADC_RES_8)
	{
		return (ADCW >> 8);
	}
	else
	{
		return 0;
	}
}
