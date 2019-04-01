///**********************************************************************************
/// Description: AS05 Testing file
/// Author: Royce Kim
/// COMSC 200 Section 5001
/// Date: March 11, 2019
/// Status : Complete 
///***********************************************************************************

#include <iostream>
#include "Circle.h"
#include "Rectangle.h"

using namespace std;

int main() {
	long x, y, length, width;
	double rad;

	cout << "\Circle's x, y center coord: ";
	cin >> x >> y;

	cout << "Enter the radius: ";
	cin >> rad;

	Circle c(x, y, rad);
	cout << "\nThe area of the circle is " << c.calcArea() << ".";

	cout << "\n\nEnter Rectangle's width and length: ";
	cin >> width >> length;

	Rectangle r(width, length);
	cout << "\nThe area of the rectangle is " << r.calcArea() << ".\n";
}