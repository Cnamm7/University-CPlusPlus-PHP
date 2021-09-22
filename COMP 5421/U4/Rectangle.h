#pragma once
#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"
class Rectangle : public Shape
{
public:

	Rectangle(const Rectangle&) = delete;
	Rectangle& operator=(const Rectangle&) = delete;

	~Rectangle() = default;

	Rectangle(unsigned int h, unsigned int w, char p, string n);
	void setHeight(unsigned int h) override;
	void setWidth(unsigned int w) override;
	double geometricArea() const override;
	double geometricPerimeter() const override;
	double textualArea() const override;
	double textualPrimeter() const override;
	Canvas draw() const override;
	//string toString() const override;

};
#endif
