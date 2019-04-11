#pragma once
#include <fstream>

class Vector2D {
	private :
	unsigned short int x;
	unsigned short int y;
	public :
	Vector2D(unsigned short int n_x = 0, unsigned short int n_y = 0) : x(n_x), y(n_y) {}

	Vector2D& operator +=(Vector2D const& v);
	Vector2D& operator -=(Vector2D const& v);
	Vector2D& operator *=(double lambda);
	Vector2D operator*(double lambda);
	Vector2D operator-(void);

	double operator |(Vector2D const& v) const;

	bool operator==(Vector2D const& v) const;
	bool operator!=(Vector2D const& v) const;
	double operator[](int i) const;

	bool is_zero(void) const; 

	double norm(void) const;
	double norm2(void) const;
	double distance(Vector2D const& v) const;
	double distance2(Vector2D const& v) const;
	Vector2D unitary(void) const;
}; 

Vector2D operator +(Vector2D v1, Vector2D const& v2);
Vector2D operator -(Vector2D v1, Vector2D const& v2);
Vector2D operator *(double lambda, Vector2D v);
std::ostream& operator<<(std::ostream& output, Vector2D const& v);
