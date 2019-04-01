///**********************************************************************************
/// Description:  ProdctionWorker Class
/// Author: Royce Kim
/// COMSC 200 Section 5001
/// Date: March 11, 2019
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
        setEmployeeNumber(9999);
        hiredDate = "00/00/9999";
        setShift(s);
        setRate(r);
    }

    ProductionWorker(std::string n, std::string hDate, int ID, int s, double r) {
        name = n;
        setEmployeeNumber(ID);
        hiredDate = hDate;
        setShift(s);
        setRate(r);
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


    //EXCEPTIONS
    class InvalidShift {
    private:
        int shiftInput;

    public:
        InvalidShift(int s) {
            shiftInput = s;
        }

        int getInput() {
            return shiftInput;
        }
    };

    class InvalidRate {
    private:
        double rateInput;

    public:
        InvalidRate(double r) {
            rateInput = r;
        }

        double getInput() {
            return rateInput;
        }

    };
};

void ProductionWorker::setShift(int s) {
    if (2 <= s && s >= 1) {
        shift = s;
    }
    else throw ProductionWorker::InvalidShift(s);
}

void ProductionWorker::setRate(double r) {
    if (r >= 0) {
        rate = r;
    }
    else throw InvalidRate(r);
}


int ProductionWorker::getShift() {
    return shift;
}
double ProductionWorker::getRate() {
    return rate;
}
