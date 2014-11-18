
#include "Arduino.h"
#include "nrf_delay.h"


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

void app_error_handler(uint32_t error_code, uint32_t line_num, const uint8_t * p_file_name)
{
	
}
