///**********************************************************************************
/// Description: holds functions for teamLeader and tester
/// Author: Royce Kim
/// COMSC 200 Section 5001
/// Date: Feb. 28, 2019
/// Status : Complete 
///***********************************************************************************
#include "TeamLeader.h"


void TeamLeader::setBonusAmount(double b) {
    bonusAmount = b;
}
void TeamLeader::setHoursInTraining(int hours) {
    hoursAttendedTraining = hours;
}

double TeamLeader::getBonusAmount() const {
    return bonusAmount;
}
int TeamLeader::getHoursInTraining() const {
    return hoursAttendedTraining;
}


int main() {
    

    TeamLeader testDummy("Test Dummy 1", "2/28/2019",3, 1, 15.80, 3,20);

    std::cout << "Entered Constructor: " << std::endl << std::endl;
    std::cout << "TeamLeader testDummy(\"Test Dummy 1\", \"2 / 28 / 2019\",3, 1, 15.80, 3,20)" << std::endl << std::endl;
    std::cout << testDummy;

    return 0;
}
