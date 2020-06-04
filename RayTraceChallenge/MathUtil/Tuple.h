#pragma once

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

double dot(const Tuple&, const Tuple&);