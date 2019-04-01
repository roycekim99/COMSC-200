///**********************************************************************************
/// Description: Header file for Rectangle
/// Author: Royce Kim
/// COMSC 200 Section 5001
/// Date: Feb. 8, 2019
/// Status : Complete 
///***********************************************************************************

// Specification file for the Rectangle class
// This version has a constructor.
#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle {
private:
    double width;
    double length;
public:
    void setWidth(double);
    void setLength(double);
    double getWidth() const;
    double getLength() const;
    double getArea() const;
};
#endif

