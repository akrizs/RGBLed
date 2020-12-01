#include "Arduino.h"

#include "RGBwLed.h"

int RGBwLed::RED[3] = {255, 0, 0};
int RGBwLed::GREEN[3] = {0, 255, 0};
int RGBwLed::BLUE[3] = {0, 0, 255};
int RGBwLed::MAGENTA[3] = {255, 0, 255};
int RGBwLed::CYAN[3] = {0, 255, 255};
int RGBwLed::YELLOW[3] = {255, 255, 0};
int RGBwLed::WHITE[3] = {255, 255, 255};

bool RGBwLed::COMMON_ANODE = true;
bool RGBwLed::COMMON_CATHODE = false;

int RGBwLed::DEF_RED = 240;
int RGBwLed::DEF_GREEN = 191;
int RGBwLed::DEF_BLUE = 41;

bool RGBwLed::RGBW = false;

int RGBwLed::FREQ = 420;

RGBwLed::RGBwLed(int r, int g, int b)
	: _red(r), _green(g), _blue(b), _common(RGBwLed::COMMON_CATHODE), _freq(RGBwLed::FREQ), _RGBW(false), _CCR(RGBwLed::DEF_RED), _CCG(RGBwLed::DEF_GREEN), _CCB(RGBwLed::DEF_BLUE)
{
	analogWriteFreq(_freq);
	pinMode(_red, OUTPUT);
	pinMode(_green, OUTPUT);
	pinMode(_blue, OUTPUT);
}

RGBwLed::RGBwLed(int r, int g, int b, bool common = RGBwLed::COMMON_CATHODE)
	: _red(r), _green(g), _blue(b), _common(common), _freq(RGBwLed::FREQ), _RGBW(false), _CCR(RGBwLed::DEF_RED), _CCG(RGBwLed::DEF_GREEN), _CCB(RGBwLed::DEF_BLUE)
{
	analogWriteFreq(_freq);
	pinMode(_red, OUTPUT);
	pinMode(_green, OUTPUT);
	pinMode(_blue, OUTPUT);
}

RGBwLed::RGBwLed(int r, int g, int b, bool common = RGBwLed::COMMON_CATHODE, int freq = RGBwLed::FREQ)
	: _red(r), _green(g), _blue(b), _common(common), _freq(freq), _RGBW(false), _CCR(RGBwLed::DEF_RED), _CCG(RGBwLed::DEF_GREEN), _CCB(RGBwLed::DEF_BLUE)
{
	analogWriteFreq(_freq);
	pinMode(_red, OUTPUT);
	pinMode(_green, OUTPUT);
	pinMode(_blue, OUTPUT);
}

RGBwLed::RGBwLed(int r, int g, int b, int w)
	: _red(r), _green(g), _blue(b), _white(w), _common(RGBwLed::COMMON_CATHODE), _freq(RGBwLed::FREQ), _RGBW(true), _CCR(RGBwLed::DEF_RED), _CCG(RGBwLed::DEF_GREEN), _CCB(RGBwLed::DEF_BLUE)
{
	RGBwLed::RGBW = true;
	analogWriteFreq(_freq);
	pinMode(_red, OUTPUT);
	pinMode(_green, OUTPUT);
	pinMode(_blue, OUTPUT);
	pinMode(_white, OUTPUT);
}

RGBwLed::RGBwLed(int r, int g, int b, int w, bool common = RGBwLed::COMMON_CATHODE)
	: _red(r), _green(g), _blue(b), _white(w), _common(common), _freq(RGBwLed::FREQ), _RGBW(true), _CCR(RGBwLed::DEF_RED), _CCG(RGBwLed::DEF_GREEN), _CCB(RGBwLed::DEF_BLUE)
{
	RGBwLed::RGBW = true;
	analogWriteFreq(_freq);
	pinMode(_red, OUTPUT);
	pinMode(_green, OUTPUT);
	pinMode(_blue, OUTPUT);
	pinMode(_white, OUTPUT);
}

RGBwLed::RGBwLed(int r, int g, int b, int w, bool common = RGBwLed::COMMON_CATHODE, int freq = RGBwLed::FREQ)
	: _red(r), _green(g), _blue(b), _white(w), _common(common), _freq(freq), _RGBW(true), _CCR(RGBwLed::DEF_RED), _CCG(RGBwLed::DEF_GREEN), _CCB(RGBwLed::DEF_BLUE)
{
	RGBwLed::RGBW = true;
	analogWriteFreq(_freq);
	pinMode(_red, OUTPUT);
	pinMode(_green, OUTPUT);
	pinMode(_blue, OUTPUT);
	pinMode(_white, OUTPUT);
}

void RGBwLed::on()
{
	color(_CCR, _CCG, _CCB);
}

void RGBwLed::off()
{
	if (_common == COMMON_ANODE)
	{
		analogWrite(_red, ~0);
		analogWrite(_green, ~0);
		analogWrite(_blue, ~0);
	}
	else
	{
		analogWrite(_red, 0);
		analogWrite(_green, 0);
		analogWrite(_blue, 0);
	}
}

void RGBwLed::brightness(int rgb[3], int brightness)
{
	intensity(rgb[0], rgb[1], rgb[2], brightness);
}

void RGBwLed::brightness(int red, int green, int blue, int brightness)
{
	intensity(red, green, blue, brightness);
}

void RGBwLed::intensity(int red, int green, int blue, int brightness)
{
	red = (red * brightness) / 100;
	green = (green * brightness) / 100;
	blue = (blue * brightness) / 100;
	color(red, green, blue);
}

void RGBwLed::flash(int rgb[3], int duration)
{
	blink(rgb[0], rgb[1], rgb[2], duration, duration);
}

void RGBwLed::flash(int rgb[3], int onDuration, int duration)
{
	blink(rgb[0], rgb[1], rgb[2], onDuration, duration);
}

void RGBwLed::flash(int red, int green, int blue, int duration)
{
	blink(red, green, blue, duration, duration);
}

void RGBwLed::flash(int red, int green, int blue, int onDuration, int duration)
{
	blink(red, green, blue, onDuration, duration);
}

void RGBwLed::blink(int red, int green, int blue, int onDuration, int duration)
{
	color(red, green, blue);
	delay(onDuration);
	off();
	delay(duration);
}

void RGBwLed::setColor(int rgb[3])
{
	color(rgb[0], rgb[1], rgb[2]);
}

void RGBwLed::setColor(int red, int green, int blue)
{
	color(red, green, blue);
}

void RGBwLed::color(int red, int green, int blue)
{
	_CCR = red;
	_CCG = green;
	_CCB = blue;
	if (_common == COMMON_ANODE)
	{
		analogWrite(_red, ~red);
		analogWrite(_green, ~green);
		analogWrite(_blue, ~blue);
	}
	else
	{
		analogWrite(_red, red);
		analogWrite(_green, green);
		analogWrite(_blue, blue);
	}
}

void RGBwLed::fadeOut(int rgb[3], int steps, int duration)
{
	fade(rgb[0], rgb[1], rgb[2], steps, duration, true);
}

void RGBwLed::fadeOut(int red, int green, int blue, int steps, int duration)
{
	fade(red, green, blue, steps, duration, true);
}

void RGBwLed::fadeIn(int rgb[3], int steps, int duration)
{
	fade(rgb[0], rgb[1], rgb[2], steps, duration, false);
}

void RGBwLed::fadeIn(int red, int green, int blue, int steps, int duration)
{
	fade(red, green, blue, steps, duration, false);
}

void RGBwLed::fade(int red, int green, int blue, int steps, int duration, bool out)
{
	if (out)
	{
		for (int i = 255; i >= 0; i -= steps)
		{
			fade(red, green, blue, steps, duration, i);
		}
	}
	else
	{
		for (int i = 0; i <= 255; i += steps)
		{
			fade(red, green, blue, steps, duration, i);
		}
	}
}

void RGBwLed::fade(int red, int green, int blue, int steps, int duration, int value)
{
	float brightness = float(value) / 255.f;
	if (red > 0 && red <= 255)
		analogWrite(_red, red * brightness);
	if (green > 0 && green <= 255)
		analogWrite(_green, green * brightness);
	if (blue > 0 && blue <= 255)
		analogWrite(_blue, blue * brightness);
	delay((unsigned long)(duration / steps));
}

void RGBwLed::initSequence()
{
	// Start by triggering each color for a short period of time.

	off();
	delay(500);
	on();
	delay(1000);
	off();
	delay(500);
	on();
	delay(1000);
	off();

	RGBwLed::flash(RGBwLed::RED, 400, 200);
	RGBwLed::flash(RGBwLed::RED, 400, 200);
	delay(1000);
	RGBwLed::flash(RGBwLed::GREEN, 400, 200);
	RGBwLed::flash(RGBwLed::GREEN, 400, 200);
	delay(1000);
	RGBwLed::flash(RGBwLed::BLUE, 400, 200);
	RGBwLed::flash(RGBwLed::BLUE, 400, 200);
	delay(1000);
}