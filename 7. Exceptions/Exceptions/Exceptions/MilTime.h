///**********************************************************************************
/// Description: Holds MilTime Class
/// Author: Royce Kim
/// COMSC 200 Section 5001
/// Date: March 31, 2019
/// Status : Complete 
///***********************************************************************************


// Specification file for the MilTime class
#ifndef MILTIME_H
#define MILTIME_H
#include "Time.h"

// Declaration of the MilTime class

class MilTime : public Time
{
private:
	int milHours;
    int milSeconds;
public:
	MilTime(int, int);

    void convert();

	void setTime(int, int);

    int getHour() 
		{ return milHours; }

    int getStandHr() 
		{ return hour; }


    class invalHour {};
    class invalSeconds {};

};

MilTime::MilTime(int h = 0, int s = 0) : Time(0, 0, s)
{
    try {
        MilTime::setTime(h, s);
    }
    catch (MilTime::invalHour) {
        std::cout << "\033[1;31mHours must be in the range 0 - 2359.\n\033[0m";
        milHours = 0;
    }
    catch (MilTime::invalSeconds) {
        std::cout << "\033[1;31mSeconds must be in the range 0 - 59.\n\033[0m";
        milSeconds = 0;
    }

    convert();
}

//***********************************************
// convert member function                      *
//***********************************************

void MilTime::convert()
{
	double temp;

	if (milHours > 1200)
		hour = milHours - 1200;
	else
		hour = milHours;
	
	hour /= 100;
	temp = (milHours - 1200) / 100.0;
	min = static_cast<int>(((temp - static_cast<int>(temp)) * 100));
}

//***********************************************
// setTime member function                      *
//***********************************************

void MilTime::setTime(int h, int s)
{
    //hour
    if (h >= 0 && h <= 2359) {
        milHours = h;
    }
    else throw MilTime::invalHour(); 
    
    //seconds
    if (s >= 0 && s <= 59) {
        milSeconds = s;
    }
    else throw MilTime::invalSeconds();
    
	convert();
}
#endif