
#include "Arduino.h"

void setup()
{
	Serial.begin(38400);
	Serial.print("Test");
	pinMode(LED_0,OUTPUT);
	digitalWrite(LED_0,HIGH);
	
}

void loop()
{

}
