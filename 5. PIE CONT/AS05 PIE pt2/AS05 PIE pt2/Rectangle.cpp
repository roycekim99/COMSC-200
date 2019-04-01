///**********************************************************************************
/// Description: Holds rectangle class functions
/// Author: Royce Kim
/// COMSC 200 Section 5001
/// Date: March 11, 2019
/// Status : Complete 
///***********************************************************************************

#include "Rectangle.h"

long Rectangle::getWidth() const {
	return width;
}

long Rectangle::getLength() const {
	return length;
}

double Rectangle::calcArea() const {
	return length * width;
}