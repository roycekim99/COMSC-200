///**********************************************************************************
/// Description: Employee test file
/// Author: Royce Kim
/// COMSC 200 Section 5001
/// Date: Feb. 8, 2019
/// Status : Complete 
///***********************************************************************************

#include "Employee.h"
#include <iomanip>
#include <iostream>
using namespace std;

void Employee::setName(string n) {
    name = n;
}

void Employee::setID(int id) {
    idNumber = id;
}

void Employee::setDepartment(string dep) {
    department = dep;
}

void Employee::setPosition(string p) {
    position = p;
}

string Employee::getName() {
    return name;
}

int Employee::getID() {
    return idNumber;
}

string Employee::getDepartment() {
    return department;
}

string Employee::getPosition() {
    return position;
}

void Employee::display() {
    cout << setw(20) << left << "Name: " << name << endl;
    cout << setw(20) << left << "ID Number: " << idNumber << endl;
    cout << setw(20) << left << "Department: " << department << endl;
    cout << setw(20) << left << "Position: " << position << endl << endl;
}

int main() {
    cout << "\033[1;32m";
    Employee("Susan Meyers", 47899, "Accounting", "Vice President").display();
    Employee("Mark Jones", 39119, "IT", "Programmer").display();
    Employee("Jay Rogers", 81774, "Manufacturing", "Engineer").display();



}