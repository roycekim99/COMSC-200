///**********************************************************************************
/// Description: holds functions of ProductionWorker
/// Author: Royce Kim
/// COMSC 200 Section 5001
/// Date: Feb. 28, 2019
/// Status : Complete 
///***********************************************************************************
#include "ProductionWorker.h"


void ProductionWorker::setShift(int s) {
    shift = s;
}
void ProductionWorker::setRate(double r) {
    rate = r;
}


int ProductionWorker::getShift() {
    return shift;
}
double ProductionWorker::getRate(){
    return rate;
}

int main() {
    std::cout << "Lab4aTestDummy(\"Lab4a Test Dummy\",\"3 / 4 / 19\",123456,2,5);" << std::endl;
    ProductionWorker Lab4aTestDummy("Lab4a Test Dummy", "3/4/19", 123456, 2, 5);
    std::cout << "returned: " << Lab4aTestDummy << std::endl;


}