#include "Arduino.h"
#include "spi_master.h"
#ifdef __cplusplus
extern "C"{
#endif
	
#include "nrf_delay.h"

	
#ifdef __cplusplus
} // extern "C"
#endif

void delay(unsigned long ms)
{
		nrf_delay_ms(ms*1000);
}

int main(void)
{
	setup();
  
	for(;;)
	{
		loop();
	}
}
