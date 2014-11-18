
#include "Arduino.h"
#include "HardwareSerial.h"
#include "SPI.h"

void setup()
{
	Serial_begin(38400);//当前不支持速率设置 
	
	pinMode(LED_0,OUTPUT);
	SPI_begin();
	Serial_print("Test");
}

void loop()
{
	
	digitalWrite(LED_0,HIGH);
	delay(1000);
	digitalWrite(LED_0,LOW);
	delay(1000);
}
