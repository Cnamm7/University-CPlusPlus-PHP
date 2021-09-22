#include "Rhombus.h"


/*
*
* Rhombus ctor
* @param unsigned int d (diagonal), char p (pen), string n (name) Default name = Diamond
*/
Rhombus::Rhombus(unsigned int d, char p, string n) : Shape(p, n)
{
    if (d % 2 == 0) { d = d + 1; }
    this->height = this->width = d;
    this->pen = p;
    this->name = n;
}
/*
*
* Rhombus Height setter
* @param unsigned int d (diagonal)
*/
void Rhombus::setHeight(unsigned int d)
{
    this->height = d;
}
/*
*
* Rhombus Width setter
* @param unsigned int d (diagonal)
*/
void Rhombus::setWidth(unsigned int d)
{
    this->width = d;
}

/*
*
* Rhombus geometric area calculator
* @ return double (h*w)/2
*/
double Rhombus::geometricArea() const
{
    return (((this->height) * (this->width)) / 2);
}
/*
*
* Rhombus geometric perimeter calculator
* @ return double 2*sqrt(2)*h
*/
double Rhombus::geometricPerimeter() const
{
    return ((2 * sqrt(2)) * this->height);
}
/*
*
* Rhombus textual area calculator
* @ return double
*/
double Rhombus::textualArea() const
{
    double n = floor(height / 2);
    return 2 * n * (n + 1) + 1;
}
/*
*
* Rhombus textual primeter calculator
* @ return double 2*(h-1)
*/
double Rhombus::textualPrimeter() const
{
    return 2 * (height - 1);
}
/*
*
* draws the rhombus
*/
Canvas Rhombus::draw() const
{

    /*
This is one of the complicated parts. firsly we should know that the
rhombus here is the symmetric one so it has a vertical and horizontal middle.
The value of the foreground increases by two and the background for each side
decreases by 1 until it reaches the half way of the height and the values would be
change inversly to the maximum height.
*/

    Canvas can{ getHeight(), getWidth() };
    unsigned r = (height) / 2 + 1;

    for (int i = 0; i <= r; i++) {
        for (int j = 1; j <= 2 * i - 1; j++)
            can.put(i, j, pen);
    }
    for (int i = r - 1; i >= 1; i--) {
        for (int j = 1; j <= 2 * i - 1; j++)
            can.put(i, j, pen);
    }

    return can;

}

//string Rhombus::toString() const
//{
//    std::stringstream ss;
//    ss << std::left
//        << "Shape Information"
//        << std::endl << "-----------------"
//        << std::endl << std::setw(25) << "id:" << identity
//        << std::endl << std::setw(25) << "Shape name:" << name
//        << std::endl << std::setw(25) << "Pen character:" << pen
//        << std::endl << std::setw(25) << "Height:" << height
//        << std::endl << std::setw(25) << "Width:" << width
//        << std::endl << std::setw(25) << "Textual area:" << textualArea()
//        << std::endl << std::setw(25) << "Geometric area:" << geometricArea()
//        << std::endl << std::setw(25) << "Textual perimeter:" << textualPrimeter()
//        << std::endl << std::setw(25) << "Geometric perimeter:" << geometricPerimeter()
//        << std::endl << std::setw(25) << "Static type:" << typeid(this).name()
//        << std::endl << std::setw(25) << "Dynamic type:" << typeid(*this).name()
//        << std::endl;
//
//    return ss.str();
//}

