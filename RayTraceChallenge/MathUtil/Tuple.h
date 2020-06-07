#pragma once
#include "Constants.h"

// A 4-dimensional vector used to represent points and vectors in 3d
// using homegeneous coordinates. A 3d vector is represented by (x, y, z, 0) and
// a 3d point is represented by (x, y, z, 1).
struct Tuple {
	double x, y, z, w;

	Tuple() : x(0), y(0), z(0), w(0) {

	}
	Tuple(double x, double y, double z, double w) : x(x), y(y), z(z), w(w)
	{

	}

	static Tuple point(double x, double y, double z);
	static Tuple vector(double x, double y, double z);

	Tuple& operator+= (const Tuple& other);
	Tuple& operator-= (const Tuple& other);

	Tuple& scale(double s);
	double magnitude() const;
	Tuple& normalize();
};

Tuple operator+ (const Tuple&, const Tuple&);
Tuple operator- (const Tuple&, const Tuple&);
Tuple operator* (double s, const Tuple& t);
Tuple operator* (const Tuple& t, double s);

// The dot product using all 4 components.
double dot(const Tuple&, const Tuple&);

// The cross product of the first 3 components, i.e. as
// vectors in R^3. W-coordinates ignores and w-coordinate of
// result is always zero.
Tuple cross(const Tuple&, const Tuple&);

bool isZero(const Tuple& t1, double tolerance = EPSILON);
bool areEqual(const Tuple& t1, const Tuple& t2, double tolerance = EPSILON);
bool areEqual(double x1, double x2, double tolerance = EPSILON);

using Point = Tuple;
using Vector = Tuple;