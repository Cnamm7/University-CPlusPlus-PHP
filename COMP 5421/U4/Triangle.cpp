#include "Triangle.h"


Triangle::Triangle(unsigned int h, unsigned w, char p, string n) : Shape(p, n)
{
	this->height = h;
	this->width = w;
}

double Triangle::geometricArea() const
{
	return (getHeight() * getWidth()) / 2;
}
