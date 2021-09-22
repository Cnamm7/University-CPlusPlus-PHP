#include "RightTriangle.h"
/*
*
* RightTriangle ctor
* @param unsigned int b (base), char p (pen), string n (name) Default name = Ladder
*/
RightTriangle::RightTriangle(unsigned int b, char p, string n) : Triangle(b, b, p, n)
{
}

/*
*
* RightTriangle Height setter
* @param unsigned int b (base)
*/
void RightTriangle::setHeight(unsigned int b)
{
	this->height = b;
}
/*
*
* RightTriangle Width setter
* @param unsigned int b (base)
*/
void RightTriangle::setWidth(unsigned int b)
{
	this->width = b;
}
/*
*
* RightTriangle geometric perimeter calculator
* @ return double (2+sqrt(2))*h
*/
double RightTriangle::geometricPerimeter() const
{
	return (2 + sqrt(2)) * this->width;
}
/*
*
* RightTriangle textual area calculator
* @ return double h*(h+1)/2
*/
double RightTriangle::textualArea() const
{
	return ((this->height * (this->height + 1)) / 2);
}
/*
*
* RightTriangle textual primeter calculator
* @ return double 3*(h-1)
*/
double RightTriangle::textualPrimeter() const
{
	return 3 * (this->height - 1);
}
/*
*
* draws the RightTriangle
*/
Canvas RightTriangle::draw() const
{
	Canvas can{ getHeight(), getWidth() };


	for (unsigned i = 0; i < height; ++i)
		for (unsigned j = 0; j < i + 1; ++j)
			can.put(i, j, pen);

	return can;
}

//string RightTriangle::toString() const
//{
//	std::stringstream ss;
//	ss << std::left
//		<< "Shape Information"
//		<< std::endl << "-----------------"
//		<< std::endl << std::setw(25) << "id:" << identity
//		<< std::endl << std::setw(25) << "Shape name:" << name
//		<< std::endl << std::setw(25) << "Pen character:" << pen
//		<< std::endl << std::setw(25) << "Height:" << height
//		<< std::endl << std::setw(25) << "Width:" << width
//		<< std::endl << std::setw(25) << "Textual area:" << textualArea()
//		<< std::endl << std::setw(25) << "Geometric area:" << geometricArea()
//		<< std::endl << std::setw(25) << "Textual perimeter:" << textualPrimeter()
//		<< std::endl << std::setw(25) << "Geometric perimeter:" << geometricPerimeter()
//		<< std::endl << std::setw(25) << "Static type:" << typeid(this).name()
//		<< std::endl << std::setw(25) << "Dynamic type:" << typeid(*this).name()
//		<< std::endl;
//
//	return ss.str();
//}
