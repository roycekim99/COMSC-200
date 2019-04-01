///**********************************************************************************
/// Description: Header for Dates
/// Author: Royce Kim
/// COMSC 200 Section 5001
/// Date: Feb. 8, 2019
/// Status : Complete 
///***********************************************************************************
#include <vector>
#include <iostream>
#include <string>
#ifndef DATE_H
#define DATE_H


class Date {
private:
    int month;
    int day;
    int year;
    std::vector<std::string> months{"Janurary", "Feburary", "March", "April" , "May", "June", "July", "August", "September", "October", "November", "December"};

    bool check() {
        int maxDays = 0;
        maxDays = (tolower(months.at(month-1).at(2)) == 'y') || (tolower(months.at(month-1).at(3)) == 'u') ||
            (tolower(months.at(month-1).at(3)) == 'c') || (tolower(months.at(month-1).at(3)) == 'y') ||
            (tolower(months.at(month-1).at(3)) == 'o') ||
            ((tolower(months.at(month-1).at(3)) == 'e') && (tolower(months.at(month-1).at(0)) == 'd'));
        
        //check max days
        maxDays = 30 + maxDays - ((tolower(months.at(month - 1).at(0)) == 'f') * 2);
        
        if (month > 0 && month < 13) {
            if (day > 0 && day < maxDays) {
                return true;
            }
            else {
                std::cout << "invalid day entered: " << day << std::endl;
                return false;
            }
        }
        else {
            std::cout << "Invalid month entered: " << month << std::endl;
            return false;
        }
    }

public:
    Date(int m, int d, int y) {
        month = m;
        day = d;
        year = y;

        check();
    }

    void setMonth(int);
    void setDay(int);
    void setYear(int);

    int const getMonth();
    int const getYear();
    int const getDay();

    void showDate1();
    void showDate2();
    void showDate3();
};

#endif // !DATE_H
