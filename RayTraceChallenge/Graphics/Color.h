#pragma once

/*
A class to represent color. The components are expected to be in
the range [0, 1] but it is not enforced.
*/
struct Color {
	double red, green, blue;

	constexpr Color(double red = 0.0, double green = 0.0, double blue = 0.0)
		: red(red), green(green), blue(blue) {
	}

	static Color White;
	static Color Black;
};

// Standard operators for combining colors.
Color operator+ (const Color& c1, const Color& c2);
Color operator- (const Color& c1, const Color& c2);
Color operator* (double scale, const Color& c);
Color operator* (const Color& c, double scale);

// Hadamard or Schur product: multiplies corresponding color components.
Color operator* (const Color& c1, const Color& c2);