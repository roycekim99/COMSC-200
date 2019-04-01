///**********************************************************************************
/// Description: contains employeeClass 
/// Author: Royce Kim
/// COMSC 200 Section 5001
/// Date: March 11, 2019
/// Status : Complete 
///***********************************************************************************
#include <string>
#include <exception>
#pragma once

class Employee {
protected:
    std::string name;
    std::string hiredDate;
    int employeeNum;

public:
    Employee() {
        name = "NA";
        setEmployeeNumber(9999);
        hiredDate = "00/00/9999";
    }

    Employee(std::string n, std::string date, int eNum) {
        name = n;
        hiredDate = date;
        setEmployeeNumber(eNum);
    }

    std::string getName() const;
    std::string getHiredDate() const;
    int getEployeeNum() const;

    void setName(std::string);
    void setHireDate(std::string);
    void setEmployeeNumber(int);

    //EXCEPTIONS
    class InvalidEmpolyeeNumber {
    private:
        int num;
    public:
        InvalidEmpolyeeNumber(int n) {
            num = n;
        }

        int getInput() {
            return num;
        }
    };


};

std::string Employee::getName() const {
    return name;
}
std::string Employee::getHiredDate() const {
    return hiredDate;
}
int Employee::getEployeeNum() const {
    return employeeNum;
}

void Employee::setName(std::string n) {
    name = n;
}
void Employee::setHireDate(std::string d) {
    hiredDate = d;
}
void Employee::setEmployeeNumber(int n) {
    if (n >= 0 && n <= 9999) {
        employeeNum = n;
    }
    else throw Employee::InvalidEmpolyeeNumber(n);
}
