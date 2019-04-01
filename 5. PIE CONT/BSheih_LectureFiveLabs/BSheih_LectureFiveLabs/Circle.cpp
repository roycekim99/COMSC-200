///**********************************************************************************
/// Description: Holds Circle class functions
/// Author: Royce Kim
/// COMSC 200 Section 5001
/// Date: March 11, 2019
/// Status : Complete 
///***********************************************************************************

#include "Circle.h"

long Circle::getCenterX() const {
	return centerX;
}

long Circle::getCenterY() const {
	return centerY;
}

double Circle::calcArea() const {
	return 3.14159 * radius * radius;
}