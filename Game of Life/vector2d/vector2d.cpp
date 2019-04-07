#include "vector2d.h"
#include "../constants/constants.h"
#include "../constants/exceptions.h"
#include <cmath>

Vector2D& Vector2D::operator +=(Vector2D const& v){
	x += v.x;
	y += v.y;
	return *this;
}

Vector2D& Vector2D::operator -=(Vector2D const& v){
	x -= v.x;
	y -= v.y;
	return *this;
}

Vector2D& Vector2D::operator *=(double lambda){
	x *= lambda;
	y *= lambda;
	return *this;
}

double Vector2D::operator |(Vector2D const& v) const{
	return x*v.x + y*v.y;
}

Vector2D Vector2D::operator-(void){
	return Vector2D(-x, -y);
}

bool Vector2D::operator==(Vector2D const& v) const{
	return (*this - v).is_zero();
}

bool Vector2D::operator!=(Vector2D const& v) const{
	return not (*this == v);	
}

Vector2D operator +(Vector2D v1, Vector2D const& v2){
	return v1 += v2;
}

Vector2D operator -(Vector2D v1, Vector2D const& v2){
	return v1 -= v2;
}

Vector2D Vector2D::operator*(double lambda){
	Vector2D Res;
	Res*=lambda;
	return Res;
}

Vector2D operator *(double lambda, Vector2D v){
	return v * lambda;
}

double Vector2D::operator[](int i) const{
	switch (i){
		case 0 : return x;
		case 1 : return y;
	}
	throw excptn::BAD_VECTOR_ACCESS;
}

bool Vector2D::is_zero(void) const{
	return this->norm2() < vctr::ZERO_VECTOR_NORM;
}

double Vector2D::norm(void) const{
	return std::sqrt((*this)|(*this));
}

double Vector2D::norm2(void) const{
	return (*this)|(*this);
}

double Vector2D::distance(Vector2D const& v) const{
	return (*this - v).norm();
}

double Vector2D::distance2(Vector2D const& v) const{
	return (*this - v).norm2();
}

Vector2D Vector2D::unitary(void) const{
	return is_zero() ? throw excptn::ZERO_VECTOR_UNITARY : (1.0/norm())*(*this);
}

std::ostream& operator<<(std::ostream& output, Vector2D const& v){
	output << v[0] << " " << v[1];
	return output;
}
