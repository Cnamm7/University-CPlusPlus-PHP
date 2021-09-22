#pragma once
#ifndef ACUTETRIANGLE_H
#define ACUTETRIANGLE_H
#include "Triangle.h"
class AcuteTriangle : public Triangle
{
public:
	AcuteTriangle(const AcuteTriangle&) = delete;
	AcuteTriangle& operator=(const AcuteTriangle&) = delete;

	~AcuteTriangle() = default;

	AcuteTriangle(unsigned int b, char p, string n);
	void setHeight(unsigned int b) override;
	void setWidth(unsigned int b) override;
	double geometricPerimeter() const override;
	double textualArea() const override;
	double textualPrimeter() const override;
	Canvas draw() const override;
	//string toString() const override;
};
#endif

