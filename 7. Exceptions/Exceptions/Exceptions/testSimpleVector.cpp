// This program demonstrates the SimpleVector template.
#include <iostream>
#include <new>		 // Needed for bad_alloc exception
#include <cstdlib>	// Needed for the exit function
#include "FeetInches.h"
#include "Frac.h"

template <class T>
class SimpleVector {
private:
	T *aptr;			 // To point to the allocated array
	int arraySize;	 // Number of elements in the array
	void memError();  // Handles memory allocation errors
	void subError();  // Handles subscripts out of range

public:
	SimpleVector() { aptr = 0; arraySize = 0;}
	SimpleVector(int);
	SimpleVector(const SimpleVector &);
	~SimpleVector();

	int size() const { return arraySize; }
	T getElementAt(int position);
	T &operator[](const int &);
	void show(); // to show the content of SimpleVector
};

template <class T>
SimpleVector<T>::SimpleVector(int s) {
	arraySize = s;
	
	// Allocate memory for the array.
	try {  aptr = new T [s]; }
	catch (std::bad_alloc) { memError(); }

	// Initialize the array.
	for (int count = 0; count < arraySize; count++)
		*(aptr + count) = 0;
}

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj) {
	arraySize = obj.arraySize;
	aptr = new T [arraySize];
	if (aptr == 0) memError();
		
	// Copy the elements of obj's array.
	for(int count = 0; count < arraySize; count++)
		*(aptr + count) = *(obj.aptr + count);
}

template <class T>
SimpleVector<T>::~SimpleVector() {
	if (arraySize > 0) delete [] aptr;
}

template <class T>
void SimpleVector<T>::memError() {
	std::cout << "ERROR:Cannot allocate memory.\n";
	exit(EXIT_FAILURE);
}

template <class T>
void SimpleVector<T>::subError() {
	std::cout << "ERROR: Subscript out of range.\n";
	exit(EXIT_FAILURE);
}

template <class T>
T SimpleVector<T>::getElementAt(int sub) {
	if (sub < 0 || sub >= arraySize) subError();
	return aptr[sub];
}

template <class T>
T &SimpleVector<T>::operator[](const int &sub) {
	if (sub < 0 || arraySize <= sub ) subError();
	return aptr[sub];
}

template <class T> // to show the content of SimpleVector
void SimpleVector<T>::show() {
	std::cout << "These initialized values are\nTable: ";
	for (int count = 0; count < arraySize; count++) 
		std::cout << getElementAt(count) << " ";
};
	
using namespace std;

int main() {
	const int SIZE = 10;	 // Number of elements
	int count;				  // Loop counter
	
	SimpleVector<int> intTable(SIZE);
	SimpleVector<double> doubleTable(SIZE);
	SimpleVector<Frac> fracTable(SIZE);
	SimpleVector<FeetInches>fiTable(SIZE);

	Frac f("1/3");
	FeetInches fi("1'3");
	// Store values in the four SimpleVectors.
	for (count = 0; count < SIZE; count++) {
		intTable[count] = (count * 2);
		doubleTable[count] = (count * 2.14);
		fracTable[count] += f++ ;
		fiTable[count] += fi++;
	}

	// Display the values in the SimpleVectors.
	cout << "These initialized values are:";
	cout << "\nintTable: "; intTable.show();
	cout << "\ndoubleTable: "; doubleTable.show();
	cout << "\nfracTable: "; fracTable.show();
	cout << "\nfeetInchesTable: "; fiTable.show();
}

