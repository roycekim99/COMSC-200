///**********************************************************************************
/// Description: Holds angle class
/// Author: Royce Kim
/// COMSC 200 Section 5001
/// Date: Feb. 10, 2019
/// Status : Complete 
///***********************************************************************************
#pragma once
#include <math.h>
#include <iostream>
#include <sstream>

class Angle {
private:
    int degrees;
    int minutes;
    float seconds;
    char direction;
public:

    Angle() {
        degrees = 0;
        minutes = 0;
        seconds = 0;
        direction = 'N';
    }
    //*******************************************
    //Lat = 0; Lon = 1;
    //*******************************************
    Angle(double gpsVal, bool longitude) {
        degrees = fabs(gpsVal);
        minutes = ((fabs(gpsVal) - degrees) * 60);
        seconds = (((fabs(gpsVal) - degrees) * 60) - minutes) *60;

        direction = (!longitude) ? ((fabs(gpsVal) == gpsVal)? 'N' : 'S') : ((fabs(gpsVal) == gpsVal) ? 'E' : 'W');
        
    }

    Angle(int d, int m, float s, char di) {
        degrees = d;
        minutes = m;
        seconds = s;
        direction = di;
    }

    void setDegrees(int);
    void setMinutes(int);
    void setSeconds(float s);
    void setDirection(char d);

    int getDegrees();
    int getMinutes();
    float getSeconds();
    char getDirection();

    void print();
    std::string toString();


};