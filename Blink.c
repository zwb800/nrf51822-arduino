
#include "Arduino.h"
#include "HardwareSerial.h"

#ifdef Blink

void setup()
{
	pinMode(LED_0,OUTPUT);
	Serial_begin(38400);
}

void loop()
{
	
	digitalWrite(LED_0,HIGH);
	delay(1000);
	digitalWrite(LED_0,LOW);
	delay(1000);
}
#endif
