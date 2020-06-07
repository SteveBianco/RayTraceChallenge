#include "Tuple.h"
#include <math.h>
#include "Constants.h"

//static 
Tuple Tuple::point(double x, double y, double z) {
	return Tuple(x, y, z, 1.0);
}

//static 
Tuple Tuple::vector(double x, double y, double z) {
	return Tuple(x, y, z, 0.0);
}

Tuple& Tuple::operator+= (const Tuple& other) {
	x += other.x;
	y += other.y;
	z += other.z;
	w += other.w;
	return *this;
}

Tuple& Tuple::operator-= (const Tuple& other) {
	x -= other.x;
	y -= other.y;
	z -= other.z;
	w -= other.w;
	return *this;
}

Tuple& Tuple::scale(double s)
{
	x *= s;
	y *= s;
	z *= s;
	w *= s;
	return *this;
}

double Tuple::magnitude() const
{
	return sqrt(dot(*this, *this));
}

Tuple& Tuple::normalize() {
	double length = magnitude();

	if (length < EPSILON) {
		//TODO throw better excption
		throw "Cannot normalize zero vector";
	}

	scale(1.0 / length);
	return *this;
}

Tuple operator+ (const Tuple& t1, const Tuple& t2)
{
	return Tuple(t1.x + t2.x, t1.y + t2.y, t1.z + t2.z, t1.w + t2.w);
}

Tuple operator- (const Tuple& t1, const Tuple& t2) {
	return Tuple(t1.x - t2.x, t1.y - t2.y, t1.z - t2.z, t1.w - t2.w);
}

Tuple operator* (double s, const Tuple& t) {
	return Tuple(s * t.x, s * t.y, s * t.z, s * t.w);
}

Tuple operator*(const Tuple& t, double s)
{
	return operator*(s, t);
}

double dot(const Tuple& t1, const Tuple& t2) {
	return t1.x * t2.x + t1.y * t2.y + t1.z * t2.z + t1.w * t2.w;
}

Tuple cross(const Tuple& a, const Tuple& b) {
	return Tuple(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x, 0);
}

bool isZero(const Tuple& t1, double tolerance) {
	return dot(t1, t1) < tolerance * tolerance;
}

bool areEqual(const Tuple& t1, const Tuple& t2, double tolerance) {
	const auto diff = t1 - t2;
	return isZero(diff);
}

bool areEqual(double x1, double x2, double tolerance) {
	return fabs(x1 - x2) < tolerance;
}