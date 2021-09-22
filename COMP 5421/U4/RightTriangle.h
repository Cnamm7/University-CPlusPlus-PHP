#pragma once
#ifndef RIGHTTRIANGLE_H
#define RIGHTTRIANGLE_H
#include "Triangle.h"
class RightTriangle : public Triangle
{
public:
	RightTriangle(const RightTriangle&) = delete;
	RightTriangle& operator=(const RightTriangle&) = delete;

	~RightTriangle() = default;

	RightTriangle(unsigned int b, char p, string n);
	void setHeight(unsigned int b) override;
	void setWidth(unsigned int b) override;
	double geometricPerimeter() const override;
	double textualArea() const override;
	double textualPrimeter() const override;
	Canvas draw() const override;
	//string toString() const override;

};
#endif

