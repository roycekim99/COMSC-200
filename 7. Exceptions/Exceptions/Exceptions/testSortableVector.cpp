///**********************************************************************************
/// Description: Driver class for Sortablevector
/// Author: Royce Kim
/// COMSC 200 Section 5001
/// Date: March 31, 2019
/// Status : Complete 
///***********************************************************************************

// Lab 7b sample test driver
//  for Sortable Vector Class Template
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "SortableVector.h"
using namespace std;

int main() {
	const int SIZE = 5;  // The array size

	// Define SortableVector objects.
	SortableVector<int> intTable(SIZE); 
	SortableVector<double> doubleTable(SIZE); 

	// Place values into the arrays in descending order.
	for (int x = 0; x < SIZE ; x++) {
		intTable[x] = SIZE - x;
		doubleTable[x]= SIZE - (x * 1.1f);
	}

	// Display the values in the arrays.
	cout << "Before sorting, these values are in intTable:\n";
	for (int x = 0; x < SIZE; x++)
		cout << intTable[x] << "  ";
	cout << "\nBefore sorting, these values are in doubleTable:\n";
	for (int x = 0; x < SIZE; x++)
		cout << doubleTable[x] << "  ";
	
	// Sort the arrays.
	intTable.Sort();
	doubleTable.Sort();

	cout << "\nAfter sorting, these values are in intTable:\n";
	for (int x = 0; x < SIZE; x++)
		cout << intTable[x] << "  ";
	cout << "\nAfter sorting, these values are in doubleTable:\n";
	for (int x = 0; x < SIZE; x++)
		cout << doubleTable[x] << "  ";
}