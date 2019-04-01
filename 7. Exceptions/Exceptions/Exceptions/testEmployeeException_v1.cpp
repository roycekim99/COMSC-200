///**********************************************************************************
/// Description: Driver class for Employees
/// Author: Royce Kim
/// COMSC 200 Section 5001
/// Date: March 11, 2019
/// Status : Complete 
///***********************************************************************************
// testEmployeeException_v1.cpp
// InvalidEmployeeNumber Exception as an external class
// However, the following two exception as a subclass!
// ProductionWorker::InvalidShift
// ProductionWorker::InvalidPayRate

#include <iostream>
#include <iomanip>
#include <sstream>
#include "ProductionWorker.h"
using namespace std;

// Function prototypes
ProductionWorker *createProductionWorker(
    string, string, string, int, double);

int main() {
    ProductionWorker *pwPtr = nullptr;
    
    // if your IDE does not support lambda, change it to a function
    auto display = [](ProductionWorker e) {
        cout << setprecision(2) << fixed << showpoint
            << "\nName: " << e.getName() 
            << "\nEmployee number: " << e.getEployeeNum() 
            << "\nHire date: " << e.getHiredDate() 
            << "\nShift: " << ((e.getShift() == 1) ? "Day" : "Night")
            << "\nShift number: " << e.getShift() 
            << "\nPay rate: " << e.getRate() << endl;
    };
    
    // A valid ProductionWorker
    pwPtr = createProductionWorker("John Jones", "123", "1/1/2006", 2, 18.00);
    if (pwPtr != nullptr) display(*pwPtr);
    
    cout << endl << endl;
    // A ProductionWorker w/invalid employee number.
    pwPtr = createProductionWorker("John Jones", "99999", "1/1/2006", 2, 18.00);
    if (pwPtr != nullptr) display(*pwPtr);

    cout << endl << endl;
    // a ProductionWorker w/invalid shift number.
    pwPtr = createProductionWorker("John Jones", "123", "1/1/2006", 0, 18.00);
    if (pwPtr != nullptr) display(*pwPtr);

    cout << endl << endl;
    // a ProductionWorker w/invalid hourly pay rate.
    pwPtr = createProductionWorker("John Jones", "123", "1/1/2006", 2, -99);
    if (pwPtr != nullptr) display(*pwPtr);
    
    return 0;
}

// The createProductionWorker function construct 
// a ProductionWorker object and returns a pointer to it. 
// If any of the values passed as arguments are invalid, 
// a null pointer is returned. 
ProductionWorker *createProductionWorker(string name,string number, string hireDate, int shift, double payRate){
	ProductionWorker *pwPtr = nullptr;
    int intID;
    std::stringstream(number) >> intID;
	try
	{
		// Create a ProductionWorker object.
		pwPtr = new ProductionWorker(name, hireDate, intID, shift, payRate);
	}
	
	////////////////////////////////////////////////
	// To catch all exceptions that you have defined in the section below

    catch (ProductionWorker::InvalidShift e) {
        std::cout << "\033[1;31mERROR: Invalid Shift. Recieved: \033[0;m" << e.getInput();
    }
    catch (Employee::InvalidEmpolyeeNumber e) {
        std::cout << "\033[1;31mERROR: Invalid Employee Number. Recieved: \033[0;m" << e.getInput();
    }

    catch (ProductionWorker::InvalidRate e) {
        std::cout << "\033[1;31mERROR: Invalid Payrate. Recieved: \033[0;m" << e.getInput();
    }

    ///////////////////////////////////////////////
  
	catch (...) {// catch-all handler
		std::cout << "We caught an exception of an undetermined type\n";
	}

	return pwPtr;
}