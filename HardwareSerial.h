#include <stdint.h>

class HardwareSerial
{
	public:
		 void begin(unsigned long);
		 void print(const char*);
};



extern HardwareSerial Serial;

