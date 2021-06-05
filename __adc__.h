#ifndef __ADC___H_
#define __ADC___H_

//#define __ADC_RES_8_BIT
#define __ADC_RES_10_BIT

#include <__swarm_wold__.h>

void _adc_init(void);
int _adc_read(uint8_t channel);

#endif /* __ADC___H_ */