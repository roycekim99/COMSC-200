///**********************************************************************************
/// Description: holds prototypes for ProdctionWorker
/// Author: Royce Kim
/// COMSC 200 Section 5001
/// Date: Feb. 28, 2019
/// Status : Complete 
///***********************************************************************************
#include "Employee.h"
#include <iostream>
#pragma once

class ProductionWorker : public Employee{
protected:
    int shift;  //2 = night, 1 = day
    double rate;

public:
    ProductionWorker(int s = 1, double r = 7.1) {
        name = "NA";
        employeeNum = 9999;
        hiredDate = "00/00/9999";
        shift = s;
        rate = r;
    }

    ProductionWorker(std::string n, std::string hDate, int ID, int s, double r) {
        name = n;
        employeeNum = ID;
        hiredDate = hDate;
        shift = s;
        rate = r;
    }

    void setShift(int);
    void setRate(double);

    int getShift();
    double getRate();

    friend std::ostream &operator << (std::ostream &strm, ProductionWorker rhs) {
        return std::cout <<
            "Name: " << rhs.getName() << std::endl <<
            "ID# : " << rhs.getEployeeNum() << std::endl <<
            "Hired: " << rhs.getHiredDate() << std::endl <<
            "==Shift: " << ((rhs.getShift() == 1) ? "Day" : "Night") << std::endl <<
            "==Rate: " << rhs.getRate() << std::endl;
    }

};