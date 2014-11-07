
#include "HardwareSerial.h"
#include "boards.h"
#ifdef __cplusplus
extern "C"{
#endif
#include "simple_uart.h"
#ifdef __cplusplus
} // extern "C"
#endif


void HardwareSerial::begin(unsigned long baud)
{
	/** @snippet [Configure UART RX and TX pin] */
	int txd_pin_number = TX_PIN_NUMBER;
	int rxd_pin_number = RX_PIN_NUMBER;
	int cts_pin_number = CTS_PIN_NUMBER;
	int rts_pin_number = RTS_PIN_NUMBER;
	bool hwfc = false;
	
	simple_uart_config(rts_pin_number,
										 txd_pin_number,
										 cts_pin_number,
										 rxd_pin_number,
											hwfc);
}

void HardwareSerial::print(const char *str)
{
		simple_uart_putstring((const uint8_t*)str);
}

HardwareSerial Serial;
