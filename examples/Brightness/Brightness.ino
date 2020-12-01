#include <RGBwLed.h>

RGBwLed led(11, 10, 9, RGBwLed::COMMON_CATHODE);

void setup() {}

void loop()
{

	// Color is red with brigthness 100%
	led.setColor(RGBwLed::RED);
	delay(2000);

	// Color is red with brigthness 10%
	led.brightness(RGBwLed::RED, 10);
	delay(2000);
}
