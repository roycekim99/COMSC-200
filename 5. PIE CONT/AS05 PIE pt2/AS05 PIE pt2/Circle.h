///**********************************************************************************
/// Description: Holds Circle header files
/// Author: Royce Kim
/// COMSC 200 Section 5001
/// Date: March 11, 2019
/// Status : Complete 
///***********************************************************************************

#pragma once

#include "BasicShape.h"

class Circle : public BasicShape {
private:
	long centerX;
	long centerY;
	double radius;

public:
	Circle(long x = 0, long y = 0, double r = 0) : BasicShape() {
		centerX = x;
		centerY = y;
		radius = r;
		calcArea();
	}

	long getCenterX() const;
	long getCenterY() const;
	double calcArea() const;
};