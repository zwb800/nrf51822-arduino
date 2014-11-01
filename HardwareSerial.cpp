
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
	
  nrf_gpio_cfg_output(txd_pin_number);
  nrf_gpio_cfg_input(rxd_pin_number, NRF_GPIO_PIN_NOPULL);  

  NRF_UART0->PSELTXD = txd_pin_number;
  NRF_UART0->PSELRXD = rxd_pin_number;
/** @snippet [Configure UART RX and TX pin] */
  if (hwfc)
  {
    nrf_gpio_cfg_output(rts_pin_number);
    nrf_gpio_cfg_input(cts_pin_number, NRF_GPIO_PIN_NOPULL);
    NRF_UART0->PSELCTS = cts_pin_number;
    NRF_UART0->PSELRTS = rts_pin_number;
    NRF_UART0->CONFIG  = (UART_CONFIG_HWFC_Enabled << UART_CONFIG_HWFC_Pos);
  }

  NRF_UART0->BAUDRATE         = (UART_BAUDRATE_BAUDRATE_Baud38400 << UART_BAUDRATE_BAUDRATE_Pos);
  NRF_UART0->ENABLE           = (UART_ENABLE_ENABLE_Enabled << UART_ENABLE_ENABLE_Pos);
  NRF_UART0->TASKS_STARTTX    = 1;
  NRF_UART0->TASKS_STARTRX    = 1;
  NRF_UART0->EVENTS_RXDRDY    = 0;
}

void HardwareSerial::print(const char *str)
{
		simple_uart_putstring((const uint8_t*)str);
}

HardwareSerial Serial;
