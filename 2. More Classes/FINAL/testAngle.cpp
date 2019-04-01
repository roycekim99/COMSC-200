///**********************************************************************************
/// Description: Tests Angle class
/// Author: Royce Kim
/// COMSC 200 Section 5001
/// Date: Feb. 10, 2019
/// Status : Complete 
///***********************************************************************************
#include "Angle.h"
using namespace std;

void Angle::setDegrees(int d) {
    degrees = d;
}

void Angle::setMinutes(int m) {
    minutes = m;
}

void Angle::setSeconds(float s) {
    seconds = s;
}

void Angle::setDirection(char d) {
    direction = d;
}

int Angle::getDegrees() {
    return degrees;
}

int Angle::getMinutes() {
    return minutes;
}

float Angle::getSeconds() {
    return seconds;
}

char Angle::getDirection() {
    return direction;
}

void Angle::print() {
    cout << degrees << "\xF8 " << minutes << "' " << seconds << "\" " << direction;
}

std::string Angle::toString() {
    std::stringstream ss;
    ss << degrees << "\xF8 " << minutes << "' " << seconds << "\" " << direction;
    return ss.str();
}


int main() {
    double lat, lon;
    Angle latA, lonA;
    cout << "\n\tEnter GPS-style coordinates:"
        << "\n\t\tLatitude: (+/- 0-90.00): ";
    cin >> lat;
    cout << "\t\tLongitude: (+/- 0-180.00): ";
    cin >> lon;

    latA = Angle(lat, 0);
    lonA = Angle(lon, 1);

    cout << "\tDMS: (";
    latA.print();
    cout << ", ";
    lonA.print();
    cout << ")\n";

    // using GPS to DMS constructor
    cout << "\n\tEnter GPS-style coordinates:"
        << "\n\t\tLatitude: (+/- 0-90.00): ";
    cin >> lat;
    Angle latC(lat, 0);

    cout << "\t\tLongitude: (+/- 0-180.00): ";
    cin >> lon;
    Angle lonC(lon, 1);

    cout << "\tDMS: (";
    latC.print();
    cout << ", ";
    //lonC.print();
    cout << lonC.toString();
    cout << ")\n";

    return 0;
}