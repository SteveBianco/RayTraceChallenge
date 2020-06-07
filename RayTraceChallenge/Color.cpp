#include "Color.h"

Color::Color(double red, double green, double blue) :
	red(red), green(green), blue(blue) {

}

const Color Color::White = Color(0.0, 0.0, 0.0);
const Color Color::Black = Color(1.0, 1.0, 1.0);

Color operator+ (const Color& c1, const Color& c2) {
	return Color{ c1.red + c2.red, c1.green + c2.green, c1.blue + c2.blue };
}

Color operator- (const Color& c1, const Color& c2) {
	return Color{ c1.red - c2.red, c1.green - c2.green, c1.blue - c2.blue };
}

Color operator* (double scale, const Color& c) {
	return Color{ scale * c.red, scale * c.green, scale * c.blue };
}

Color operator* (const Color& c, double scale) {
	return scale * c;
}

Color operator* (const Color& c1, const Color& c2) {
	return Color{ c1.red * c2.red, c1.green * c2.green, c1.blue * c2.blue };
}