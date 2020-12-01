#include <RGBwLed.h>

RGBwLed led(11, 10, 9, RGBwLed::COMMON_CATHODE);

void setup() {}

void loop()
{

	// Set color to red
	led.setColor(RGBwLed::RED);
	delay(100);

	// Set color to green
	led.setColor(0, 255, 0);
	delay(100);
}
