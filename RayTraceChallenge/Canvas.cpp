#include "Canvas.h"

Canvas::Canvas(unsigned int width, unsigned int height, Color color)
	: width_(width)
	, height_(height)
	, pixels_(width * height, color) {

}