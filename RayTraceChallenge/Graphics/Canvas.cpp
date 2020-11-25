#include "Canvas.h"

#include <stdexcept>


unsigned int Canvas::toSingleIndex(unsigned int row, unsigned int col) const {
	const auto idx = width_ * row + col;

	if (idx >= pixels_.size()) {
		throw std::out_of_range("Index out of bounds");
	}

	return idx;
}


Canvas::Canvas(unsigned int width, unsigned int height, Color color)
	: width_(width)
	, height_(height)
	, pixels_(width * height, color) {

}

void Canvas::setColor(unsigned int x, unsigned int y, const Color& color) {
	const auto idx = toSingleIndex(x, y);
	pixels_[idx] = color;
}

const Color& Canvas::getColor(unsigned int x, unsigned int y) const {
	const auto idx = toSingleIndex(x, y);
	return pixels_[idx];
}