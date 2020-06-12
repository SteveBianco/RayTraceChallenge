#pragma once
#include <vector>

#include "Color.h"

// Represents a rectangular array of pixels
// with a specified width and height.
class Canvas {
	unsigned int width_, height_;
	std::vector<Color> pixels_;


	unsigned int toSingleIndex(unsigned int row, unsigned int col) const;

public:
	Canvas(unsigned int width, unsigned int height, Color fillColor = Color::White);

	void setPixel(unsigned int x, unsigned int y, const Color& color);
	const Color& getColor(unsigned int x, unsigned int y) const;
};