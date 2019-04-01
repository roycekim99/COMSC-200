///**********************************************************************************
/// Description: Holds Rectangle header files
/// Author: Royce Kim
/// COMSC 200 Section 5001
/// Date: March 11, 2019
/// Status : Complete 
///***********************************************************************************

#pragma once

#include "BasicShape.h"

class Rectangle : public BasicShape {
private:
	long width;
	long length;

public:
	Rectangle(long w = 0, long l = 0) : BasicShape() {
		width = w;
		length = l;
		calcArea();
	}

	long getWidth() const;
	long getLength() const;
	double calcArea() const;
};