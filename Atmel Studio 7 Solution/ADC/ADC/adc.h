/*
 * adc.h
 *
 * Created: 6/5/2021 3:32:58 AM
 *  Author: Adnan Saood (adnan.saood@outlook.com)
 */ 


#ifndef ADC_H_
#define ADC_H_

#define _ADC_RES_10 10
#define _ADC_RES_8 8

#define _Aref_1v1 1
#define _Aref_VCC 2

/**
 * This is the initialization function for 10 bit conversions
 * 
*/
void adcInit(uint8_t Aref, uint8_t resolution);

/**
 * This is the read function
 * 
*/
uint16_t adcRead(uint8_t channel);


#endif /* ADC_H_ */