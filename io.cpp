#include "stdint.h"
#include "nrf_gpio.h"
#include "Arduino.h"

/**gpioº¯Êý
*/

void pinMode(uint8_t pin, uint8_t dir)
{
	if(dir== OUTPUT)
	{
		nrf_gpio_cfg_output(pin);
	}
}

void digitalWrite(uint8_t pin, uint8_t val)
{
		nrf_gpio_pin_write(pin,val);
}
