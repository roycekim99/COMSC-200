///**********************************************************************************
/// Description: Calculates the area of a rectangle
/// Author: Royce Kim
/// COMSC 200 Section 5001
/// Date: Feb. 8, 2019
/// Status : Complete 
///***********************************************************************************

#include <iostream>
#include <sstream>
#include "Rectangle.h"
using namespace std;


void Rectangle::setWidth(double w) {
    width = w;
}

void Rectangle::setLength(double l) {
    length = l;
}

double Rectangle::getWidth() const{
    return width;
}

double Rectangle::getLength() const{
    return length;
}

double Rectangle::getArea() const {
    return width * length;
}

int main() {
    double inputNum;
    unique_ptr<Rectangle> rect(new Rectangle);
    string userInput;
    
    cout << "\033[1;32mThis program will calculate the area of a\nrectangle. What is the width? ";
    getline(cin, userInput);
    stringstream(userInput) >> inputNum;
    rect->setWidth(inputNum);

    cout << endl <<  "What is the length? ";
    getline(cin, userInput);
    stringstream(userInput) >> inputNum;
    rect->setLength(inputNum);

    cout << endl << endl << "Here is the inputed data:" << endl;
    cout << "Width: " << rect->getWidth() << endl;
    cout << "Length: " << rect->getLength() << endl;
    cout << "[Area]: " << rect->getArea() << endl;

    return 0;
}
