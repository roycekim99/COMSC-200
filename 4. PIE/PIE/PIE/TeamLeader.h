///**********************************************************************************
/// Description: holds prototypes for Team Leader
/// Author: Royce Kim
/// COMSC 200 Section 5001
/// Date: Feb. 28, 2019
/// Status : Complete 
///***********************************************************************************
#include "ProductionWorker.h"
#include "Employee.h"
#pragma once

class TeamLeader : public ProductionWorker{
private:
    double bonusAmount;
    int hoursAttendedTraining;

public:
    TeamLeader(double bonus = 0, int hoursAttended = 0) {
        name = "NA";
        employeeNum = 9999;
        hiredDate = "00/00/9999";   
        rate = 7.1;
        shift = 1;
        bonusAmount = bonus;
        hoursAttendedTraining = hoursAttended;;
    }

    TeamLeader(std::string n, std::string hireDate, int ID, int s, double r, double bonus, int hoursAttended) {
        name = n;
        employeeNum = ID;
        hiredDate = hireDate;
        rate = r;
        shift = s;
        bonusAmount = bonus;
        hoursAttendedTraining = hoursAttended;
    }

    void setBonusAmount(double);
    void setHoursInTraining(int);

    double getBonusAmount() const;
    int getHoursInTraining() const;

    friend std::ostream &operator << (std::ostream &strm,  TeamLeader rhs) {
        return std::cout <<
            "Name: " << rhs.getName() << std::endl <<
            "ID# : " << rhs.getEployeeNum() << std::endl << 
            "Hired: " << rhs.getHiredDate() << std::endl <<
            "==Shift: " << ((rhs.getShift() == 1)? "Day" : "Night" )<< std::endl <<
            "==Rate: " << rhs.getRate() << std::endl <<
            "==| Bonus: " << rhs.getBonusAmount() << std::endl <<
            "==| Hours in Training: " << rhs.getHoursInTraining() << std::endl;
    }

};