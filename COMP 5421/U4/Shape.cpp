#include "Shape.h"
/*
*
* Shape ctor
* @param char p (pen), string n (name)
*/
Shape::Shape(char p, string n)
    :pen{ p }, name{ n }
{
    this->identity++;
}
/*
*
* Shape name getter
* @ return name
*/
string Shape::getName() const
{
    return this->name;
}
/*
*
* Shape Id getter
* @ return Id
*/
int Shape::getIdentity() const
{
    return this->identity;
}
/*
*
* Shape pen getter
* @ return pen
*/
char Shape::getPen() const
{
    return this->pen;
}
/*
*
* Shape height getter
* @ return height
*/
int Shape::getHeight() const
{
    return this->height;
}
/*
*
* Shape width getter
* @ return width
*/
int Shape::getWidth() const
{
    return this->width;
}
/*
*
* Shape name setter
* @ param string n name
*/
void Shape::setName(string n)
{
    this->name = n;
}
/*
*
* Shape pen setter
* @ param char p pen
*/
void Shape::setPen(char p)
{
    this->pen = p;
}

//-------------------------------------------------

string Shape::toString() const
{
    std::stringstream ss;
    ss << std::left
        << "Shape Information"
        << std::endl << "-----------------"
        << std::endl << std::setw(25) << "id:" << identity
        << std::endl << std::setw(25) << "Shape name:" << name
        << std::endl << std::setw(25) << "Pen character:" << pen
        << std::endl << std::setw(25) << "Height:" << height
        << std::endl << std::setw(25) << "Width:" << width
        << std::endl << std::setw(25) << "Textual area:" << textualArea()
        << std::endl << std::setw(25) << "Geometric area:" << geometricArea()
        << std::endl << std::setw(25) << "Textual perimeter:" << textualPrimeter()
        << std::endl << std::setw(25) << "Geometric perimeter:" << geometricPerimeter()
        << std::endl << std::setw(25) << "Static type:" << typeid(this).name()
        << std::endl << std::setw(25) << "Dynamic type:" << typeid(*this).name()
        << std::endl;

    return ss.str();
}
//-------------------------------------------------
//string Shape::toString() const
//{
//	string text;
//	ostringstream width;
//	ostringstream height;
//	ostringstream geometricArea;
//	ostringstream textualArea;
//	ostringstream geometricPerimeter;
//	ostringstream textualPerimeter;
//
//	text.append("id:\t\t" + std::to_string(this->identity) + "\n");
//	text.append("Shape name:\t" + this->name + "\n");
//	text.append("Pen character:\t" + this->pen);
//
//	height << std::fixed;
//	height.precision(2);
//	height << this->getHeight();
//	text.append("B. box height:\t" + height.str() + "\n");
//
//	width << std::fixed;
//	width.precision(2);
//	width << this->getWidth();
//	text.append("B. box width:\t" + width.str() + "\n");
//
//	textualArea << std::fixed;
//	textualArea.precision(2);
//	textualArea << this->textualArea();
//	text.append("Scr area:\t" + textualArea.str() + "\n");
//
//	geometricArea << std::fixed;
//	geometricArea.precision(2);
//	geometricArea << this->geometricArea();
//	text.append("Geo area:\t" + geometricArea.str() + "\n");
//
//	textualPerimeter << std::fixed;
//	textualPerimeter.precision(2);
//	textualPerimeter << this->textualPrimeter();
//	text.append("Scr perimeter:\t" + textualPerimeter.str() + "\n");
//
//	geometricPerimeter << std::fixed;
//	geometricPerimeter.precision(2);
//	geometricPerimeter << this->geometricPerimeter();
//	text.append("Geo perimeter:\t" + geometricPerimeter.str() + "\n");
//
//	text.append("Static type:\t");
//	text.append(typeid(this).name());
//	text.append("\n");
//	text.append("Dynamic type:\t");
//	text.append(typeid(*this).name());
//	text.append("\n");
//	return text;
//}

//ostream& operator<<(ostream& out, Shape& shp)
ostream& operator<< (ostream& out, const Shape& shp)
{
    out << shp.toString();
    return out;
}
