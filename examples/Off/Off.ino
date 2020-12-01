#include <RGBwLed.h>

RGBwLed led(11, 10, 9, RGBwLed::COMMON_CATHODE);

void setup() {}

void loop()
{

	// Light off RGB led
	led.off();
}
