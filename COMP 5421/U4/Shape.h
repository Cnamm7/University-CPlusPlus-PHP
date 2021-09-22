#pragma once
#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <math.h>
#include <iostream>
#include <sstream>
#include "Canvas.h"
#include <iomanip>
// abstract class
using std::string;
using std::ostringstream;
using std::endl;

class Shape
{
protected:
	string name;
	size_t identity{ 0 };
	char pen{ '*' };
	unsigned int height{ 0 };
	unsigned int width{ 0 };


public:
	//Shape();
	Shape(char p, string n);

	Shape(const Shape&) = delete;
	Shape& operator=(const Shape&) = delete;

	virtual ~Shape() = default;

	string getName() const;
	int getIdentity() const;
	char getPen() const;
	int getHeight() const;
	int getWidth() const;

	void setName(string n);
	void setPen(char p);

	virtual string toString() const;// = 0; why virtual?

	virtual void setHeight(unsigned int h) = 0;
	virtual void setWidth(unsigned int w) = 0;
	virtual double geometricArea() const = 0;
	virtual double geometricPerimeter() const = 0;
	virtual double textualArea() const = 0;
	virtual double textualPrimeter() const = 0;
	virtual Canvas draw() const = 0;
};

#endif // SHAPE_H

ostream& operator<< (ostream& out, const Shape& shp);

