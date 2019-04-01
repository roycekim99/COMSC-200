///**********************************************************************************
/// Description: contains employeeClass Prototypes
/// Author: Royce Kim
/// COMSC 200 Section 5001
/// Date: Feb. 28, 2019
/// Status : Complete 
///***********************************************************************************
#include <string>
#pragma once

class Employee {
protected:
    std::string name;
    std::string hiredDate;
    int employeeNum;

public:
    Employee() {
        name = "NA";
        employeeNum = 9999;
        hiredDate = "00/00/9999";
    }

    Employee(std::string n, std::string date, int eNum) {
        name = n;
        hiredDate = date;
        employeeNum = eNum;
    }

    std::string getName() const;
    std::string getHiredDate() const;
    int getEployeeNum() const;

    void setName(std::string);
    void setHireDate(std::string);
    void setEmployeeNumber(int);


};
