
#include "Arduino.h"
#ifdef Blink
void setup()
{
	pinMode(LED_0,OUTPUT);
}

void loop()
{
	
	digitalWrite(LED_0,HIGH);
	delay(1000);
	digitalWrite(LED_0,LOW);
	delay(1000);
}
#endif
