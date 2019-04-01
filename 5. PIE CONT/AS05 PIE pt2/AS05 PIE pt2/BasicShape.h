///**********************************************************************************
/// Description: Holds Basic Shape class
/// Author: Royce Kim
/// COMSC 200 Section 5001
/// Date: March 11, 2019
/// Status : Complete 
///***********************************************************************************

#pragma once

class BasicShape {
protected:
	double area;

public:
	double getArea() const {
		return area;
	}
	virtual double calcArea() const = 0;
	~BasicShape();
};