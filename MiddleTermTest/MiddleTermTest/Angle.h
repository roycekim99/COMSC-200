#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

class Angle{ // DMS - Degree, Minute, Second cordinate
private: 
    int degrees, minutes;
    double seconds;
    char direct;
public:
    // constructor
    Angle() {degrees=0; minutes=0; seconds=0; direct='N'; }
    // Either one of the following format
    //
    // Angle(int d, int m, double s, char dir) {
    //     degrees=d; minutes=m; seconds=s; direct=dir; 
    // }
    Angle(int d, int m, double s, char dir) 
        : degrees(d), minutes(m), seconds(s), direct(dir) {};
    Angle(Angle &a);
    Angle(double gps, int latlong);
    
    // setters & getters
    void setDegrees(int d) ;
    void setMinutes(int m);
    void setSeconds(double s);
    void setDirect(char dir);
    int getDegrees() const;
    int getMinutes() const;
    double getSeconds() const;
    char getDirect() const;
    
    Angle operator ++() {
        degrees++;
        if (degrees >= 180) {
            degrees -= 180;
        }
    }
    
    Angle operator --(int) {
        Angle dum(degrees,minutes,seconds, direct);
        degrees--;
        if (degrees < -180) {
            degrees +=180;
        }
        return dum;
    }

    operator int() {
        int temp = degrees;
        return temp;
    }

    operator double() {
        double temp;
        temp = degrees;
        temp += (static_cast<double>(minutes)/60.0);
        temp += (seconds / 3600.0);
        return temp;
    }


    // feature methods
    void print() {
        cout << std::setprecision(4) << std::fixed 
             << degrees << "° " << minutes << "' "
             << seconds << "\" " << direct;
    }
    string toString() {
        stringstream ss;
        ss << degrees << "\370 " << minutes << "' "
             << seconds << "\" " << direct;
        string s;
        ss >> s;
        return s;
    }
};