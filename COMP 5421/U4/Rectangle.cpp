#include "Rectangle.h"

/*
*
* Rectangle ctor
* @param unsigned int h (height), unsigned int w (width), char p (pen), string n (name) Default name = Rectangle
*/

Rectangle::Rectangle(unsigned int h, unsigned int w, char p, string n) : Shape(p, n)
{
    setHeight(h);
    setWidth(w);
}

/*
*
* Rectangle Height setter
* @param unsigned int h (height)
*/

void Rectangle::setHeight(unsigned int h)
{
    this->height = h;
}
/*
*
* Rectangle Width setter
* @param unsigned int w (width)
*/
void Rectangle::setWidth(unsigned int w)
{
    this->width = w;
}
/*
*
* Rectangle geometric area calculator
* @ return double h*w
*/
double Rectangle::geometricArea() const
{
    return ((this->height) * (this->width));
}

/*
*
* Rectangle geometric perimeter calculator
* @ return double 2(h+w)
*/
double Rectangle::geometricPerimeter() const
{
    double result = 2 * (this->height) + (this->width);
    return result;
}
/*
*
* Rectangle textual area calculator
* @ return double h*w
*/
double Rectangle::textualArea() const
{
    return this->height*this->width;
}
/*
*
* Rectangle textual primeter calculator
* @ return double 2(h+w)-4
*/
double Rectangle::textualPrimeter() const
{
    return (2*(this->height + this->width)) - 4;
}
/*
*
* draws the rectangle using pen
*/
Canvas Rectangle::draw() const
{
    Canvas can{ getHeight(), getWidth() };
    for (size_t i = 0; i < this->getHeight(); i++)
    {
        for (size_t j = 0; j < this->getWidth(); j++)
        {
            can.put(i, j, pen);
        }
    }
    
    return can;
}
/*
*
* print the rectangle info completely
*/
//string Rectangle::toString() const
//{
//
//    std::stringstream ss;
//    ss << std::left
//       << "Shape Information"
//       << std::endl << "-----------------"
//       << std::endl << std::setw(25) << "id:" << identity
//       << std::endl << std::setw(25) << "Shape name:" << name
//       << std::endl << std::setw(25) << "Pen character:" << pen
//       << std::endl << std::setw(25) << "Height:" << height
//       << std::endl << std::setw(25) << "Width:" << width
//       << std::endl << std::setw(25) << "Textual area:" << textualArea()
//       << std::endl << std::setw(25) << "Geometric area:" << geometricArea()
//       << std::endl << std::setw(25) << "Textual perimeter:" << textualPrimeter()
//       << std::endl << std::setw(25) << "Geometric perimeter:" << geometricPerimeter()
//       << std::endl << std::setw(25) << "Static type:" << typeid(this).name()
//       << std::endl << std::setw(25) << "Dynamic type:" << typeid(*this).name()
//       << std::endl;
//
//    return ss.str();
//}



