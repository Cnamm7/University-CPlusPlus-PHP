#pragma once
#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Shape.h"
// abstract class
class Triangle : public Shape
{
protected:
	Triangle(unsigned int h, unsigned w, char p, string n);

	Triangle(const Triangle&) = delete;
	Triangle& operator=(const Triangle&) = delete;

	virtual ~Triangle() = default;

	virtual double geometricArea() const override;
	virtual void setHeight(unsigned int h) = 0;
	virtual void setWidth(unsigned int w) = 0;
	virtual double geometricPerimeter() const = 0;
	virtual double textualArea() const = 0;
	virtual double textualPrimeter() const = 0;
	virtual Canvas draw() const = 0;
	//virtual string toString() const = 0;

};

#endif

