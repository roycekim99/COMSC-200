///**********************************************************************************
/// Description: Test car class
/// Author: Royce Kim
/// COMSC 200 Section 5001
/// Date: Feb. 9, 2019
/// Status : Complete 
///***********************************************************************************
#include "Car.h"
#include <iostream>
#include <memory>

void Car::setYearModel(int ym) {
    yearModel = ym;
}

void Car::setSpeed(int sp) {
    speed = sp;
}

void Car::setMake(std::string m) {
    make = m;
}

int Car::getYearModel() const {
    return yearModel;
}

int Car::getSpeed() const {
    return speed;
}

std::string Car::getMake() const {
    return make;
}

void Car::accelerate() {
    speed += 5;
}

void Car::brake() {
    speed -= 5;
}

int main() {
    //creates a test dummy
    std::unique_ptr<Car> testDummy(new Car(1990, "Prius"));

    //first display
    std::cout << "\033[1;32mInit: " << testDummy->getSpeed() << std::endl;

    //calls accelerate and dispalys its 5 times
    for (int i = 0; i < 5; i++) {
        std::cout << "Calling accelerate()..." << std::endl;
        testDummy->accelerate();
        std::cout << "Current speed: " << testDummy->getSpeed() << std::endl;
    }
    
    //calls brake and dispalys its 5 times
    for (int i = 0; i < 5; i++) {
        std::cout << "Calling brake()..." << std::endl;
        testDummy->brake();
        std::cout << "Current speed: " << testDummy->getSpeed() << std::endl;
    }

    return 0;
}

