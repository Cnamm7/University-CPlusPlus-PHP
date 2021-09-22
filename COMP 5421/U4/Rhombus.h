#pragma once
#ifndef RHOMBUS_H
#define RHOMBUS_H
#include "Shape.h"
class Rhombus : public Shape
{
public:

	Rhombus(const Rhombus&) = delete;
	Rhombus& operator=(const Rhombus&) = delete;

	~Rhombus() = default;

	explicit Rhombus(unsigned int d, char p, string n);
	void setHeight(unsigned int d) override;
	void setWidth(unsigned int d) override;
	double geometricArea() const override;
	double geometricPerimeter() const override;
	double textualArea() const override;
	double textualPrimeter() const override;
	Canvas draw() const override;
	//string toString() const override;
};
#endif



