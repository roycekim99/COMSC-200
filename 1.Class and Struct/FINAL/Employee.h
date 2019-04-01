///**********************************************************************************
/// Description: An employee class
/// Author: Royce Kim
/// COMSC 200 Section 5001
/// Date: Feb. 8, 2019
/// Status : Complete 
///***********************************************************************************
#include <vector>
#include <string>

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee {
private:
    std::string name;
    int idNumber;
    std::string department;
    std::string position;

public:
    Employee(std::string n = "", int id = 0, std::string d = "", std::string p = "") {
        name = n;
        idNumber = id;
        department = d;
        position = p;
    }

    void setName(std::string);
    void setID(int);
    void setDepartment(std::string);
    void setPosition(std::string);

    std::string getName();
    std::string getDepartment();
    std::string getPosition();
    int getID();

    void display();


};

#endif // !EMPLOYEE_H

