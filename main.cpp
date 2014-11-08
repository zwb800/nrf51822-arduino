#include "Arduino.h"

#ifdef __cplusplus
extern "C"{
#endif
	
#include "nrf_delay.h"

#ifdef __cplusplus
} // extern "C"
#endif

void delay(unsigned long ms)
{
		nrf_delay_ms(ms);
}

int main(void)
{
	setup();
  
	for(;;)
	{
		loop();
	}
}
