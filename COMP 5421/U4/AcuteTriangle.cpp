#include "AcuteTriangle.h"
/*
*
* AcuteTriangle ctor
* @param unsigned int d (diagonal), char p (pen), string n (name) Default name = Wedge
*/

AcuteTriangle::AcuteTriangle(unsigned int b, char p, string n) : Triangle(b, b, p, n)
{
	if (b % 2 == 0) { b = b + 1; }
	this->height = b + 1 / 2;
	this->width = b;
	this->name = n;
	this->pen = p;
}
/*
*
* AcuteTriangle Height setter
* @param unsigned int b (base)
*/
void AcuteTriangle::setHeight(unsigned int b)
{
	this->height = b;
}
/*
*
* AcuteTriangle Width setter
* @param unsigned int b (base)
*/
void AcuteTriangle::setWidth(unsigned int b)
{
	this->width = b;
}
/*
*
* AcuteTriangle geometric perimeter calculator
* @ return double w+sqrt(w^2 + 4*(h^2))
*/
double AcuteTriangle::geometricPerimeter() const
{
	return width + sqrt(pow(width, 2) + 4 * pow(height, 2));
}
/*
*
* AcuteTriangle textual area calculator
* @ return double h^2
*/
double AcuteTriangle::textualArea() const
{
	return pow(height, 2);
}
/*
*
* RightTriangle textual primeter calculator
* @ return double 4*(h-1)
*/
double AcuteTriangle::textualPrimeter() const
{
	return 4 * (height - 1);
}
/*
*
* draws the RightTriangle
*/
Canvas AcuteTriangle::draw() const
{
	Canvas can{ getHeight(), getWidth() };

	for (unsigned i = 0; i < height; ++i)
		for (unsigned j = 0; j < i + 1; ++j)
			can.put(i, j, pen);
	return can;
}

//string AcuteTriangle::toString() const
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
