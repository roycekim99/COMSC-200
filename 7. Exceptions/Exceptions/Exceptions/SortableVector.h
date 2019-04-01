///**********************************************************************************
/// Description: Sortable Vector Class: sorting alg
/// Author: Royce Kim
/// COMSC 200 Section 5001
/// Date: March 31, 2019
/// Status : Complete 
///***********************************************************************************

#pragma
#include <iostream>
#include <algorithm>
#include "SimpleVector.h"

template<class T>
class SortableVector : public SimpleVector<T> {
public:
    //constructors
    SortableVector(int s) : SimpleVector<T>(s) {}

    SortableVector(SimpleVector<T> &obj) : SimpleVector<T>(obj) {}
    
    //sorting algorithm
    void Sort();
};

//sorting algorithm
template <class T>
void SortableVector<T>::Sort() {

    bool Swap;

    do {
        Swap = false;

        for (int i = 0; i < (this->size() - 1); i++) {
            if (this->operator[](i) > this->operator[](i + 1)) {
                swap(this->operator[](i), this->operator[](i + 1));
                
                
                Swap = true;
            }
        }
    }
    while (Swap);
}
