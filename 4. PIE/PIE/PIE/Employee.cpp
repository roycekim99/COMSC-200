///**********************************************************************************
/// Description: holds employee functions
/// Author: Royce Kim
/// COMSC 200 Section 5001
/// Date: Feb. 28, 2019
/// Status : Complete 
///***********************************************************************************
#include "Employee.h"
#pragma once

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
    employeeNum = n;
}
