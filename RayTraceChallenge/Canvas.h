#pragma once
#include <vector>

#include "Color.h"

// Represents a rectangular array of pixels
// with a specified width and height.
class Canvas {
	unsigned int width_, height_;
	std::vector<Color> pixels_;

public:
	Canvas(unsigned int width, unsigned int height, Color fillColor = Color::White);
};