///**********************************************************************************
/// Description: Holds the Car Class
/// Author: Royce Kim
/// COMSC 200 Section 5001
/// Date: Feb. 9, 2019
/// Status : Complete 
///***********************************************************************************

#pragma once
#include <string>


class Car {
private:
    int yearModel;
    int speed = 0;
    std::string make;

public:
    Car(int year, std::string m) {
        speed = 0;
        yearModel = year;
        make = m;
    }

    void setYearModel(int);
    void setSpeed(int);
    void setMake(std::string);

    int getYearModel() const;
    int getSpeed() const;
    std::string getMake() const;

    void accelerate();  //add 5 to speed
    void brake();       //subtract 5 to speed
};