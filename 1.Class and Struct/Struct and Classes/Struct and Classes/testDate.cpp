///**********************************************************************************
/// Description: Calculates the area of a rectangle
/// Author: Royce Kim
/// COMSC 200 Section 5001
/// Date: Feb. 8, 2019
/// Status : Complete 
///***********************************************************************************
#include "Date.h"
#include <iostream>
using namespace std;

void Date::setMonth(int m) {
    month = m;
}

void Date::setDay(int d) {
    day = d;
}

void Date::setYear(int y) {
    year = y;
}

int const Date::getMonth() {
    return month;
}

int const Date::getDay() {
    return day;
}

int const Date::getYear() {
    return year;
}

void Date::showDate1() {
    if (check()) {
        cout << month << "/" << day << "/" << year << endl;
    }
}
void Date::showDate2() {
    if (check()) {
        cout << months.at(month - 1) << " " << day << "," << year << endl;
    }
}
void Date::showDate3() {
    if (check()) {
        cout << day << " " << months.at(month - 1) << " " << year << endl;
    }
}

int main() {
    // using the overloaded constructor.
    Date today(12, 25, 2012);

    // Show the date in form #1.
    today.showDate1();

    // Store a new month, day, and year
    // in the object.
    today.setMonth(8);
    today.setDay(16);
    today.setYear(2012);

    // Show the date in form #2.
    today.showDate2();

    // Show the date in form #3.
    today.showDate3();

    // Test invalid date.
    Date someday(12, 32, 2012);

    return 0;
}