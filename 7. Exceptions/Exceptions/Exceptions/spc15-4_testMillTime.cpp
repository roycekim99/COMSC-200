///**********************************************************************************
/// Description: Holds driver for MilTime
/// Author: Royce Kim
/// COMSC 200 Section 5001
/// Date: March 31, 2019
/// Status : Complete 
///***********************************************************************************

// Chapter 15, Programming Challege 4: Time Format
#include <iostream>
#include "MilTime.h"
using namespace std;

int main()
{
    // Create a MilTime object for 1445 hours, 27 seconds.
    MilTime timeObj(1445, 27);

    // Display the hours, minutes, and seconds.
    cout << "The hour in military format is "
        << timeObj.getHour() << endl;
    cout << "The hour in standard format is "
        << timeObj.getStandHr() << endl;
    cout << "The minutes are "
        << timeObj.getMin() << endl;
    cout << "The seconds are "
        << timeObj.getSec() << endl;


    cout << endl << endl;
    // Create a MilTime object for 1445 hours, 27 seconds.
    MilTime timeObj1(-1, 27);

    // Display the hours, minutes, and seconds.
    cout << "The hour in military format is "
        << timeObj1.getHour() << endl;
    cout << "The hour in standard format is "
        << timeObj1.getStandHr() << endl;
    cout << "The minutes are "
        << timeObj1.getMin() << endl;
    cout << "The seconds are "
        << timeObj1.getSec() << endl;


    cout << endl << endl;
    // Create a MilTime object for 1445 hours, 27 seconds.
    MilTime timeObj2(1445, -1);

    // Display the hours, minutes, and seconds.
    cout << "The hour in military format is "
        << timeObj2.getHour() << endl;
    cout << "The hour in standard format is "
        << timeObj2.getStandHr() << endl;
    cout << "The minutes are "
        << timeObj2.getMin() << endl;
    cout << "The seconds are "
        << timeObj2.getSec() << endl;
   return 0;
}