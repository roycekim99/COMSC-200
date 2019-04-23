#include <stdio.h>
#include <iostream>

using namespace std;

/***************************************************************
Problem: Merge Sort
Question: Create merge sort algorithm for built in arrays
Name: Brandon Sheih
ID: 1646114
Date: 10/23/2018
Status: not complete
****************************************************************/

void merge(int *array, int lowIndex1, int highIndex1, int lowIndex2, int highIndex2) {
    const int tempSize = highIndex2 - lowIndex1;
    int tmpArray[tempSize];


    for (int i = lowIndex1; i <= highIndex2; i++) {
        cout << "Before Switch" << endl;
        cout << "lowIndex1: " << lowIndex1 << endl;
        cout << "array[lowIndex1]: " << array[lowIndex1] << endl;
        cout << "lowIndex2: " << lowIndex2 << endl;
        cout << "array[lowIndex2]: " << array[lowIndex2] << endl << endl;
        if (array[lowIndex1] <= array[lowIndex2]) {
            tmpArray[i] = array[lowIndex1];
            ++lowIndex1;
        }
        else {
            tmpArray[i] = array[lowIndex2];
            if (highIndex2 - lowIndex2 >= 1) {
                ++lowIndex2;
            }
            else {
                tmpArray[i + 1] = array[lowIndex1];
                i++;
            }
        }
    }


    for (int i = lowIndex1; i <= highIndex2; i++) {
        array[i] = tmpArray[i];
    }


    cout << "After Switch" << endl;
    cout << "lowIndex1: " << lowIndex1 << endl;
    cout << "array[lowIndex1]: " << array[lowIndex1] << endl;
    cout << "lowIndex2: " << lowIndex2 << endl;
    cout << "array[lowIndex2]: " << array[lowIndex2] << endl << endl;



}

void mergeSort(int *array, int size, int lowIndex, int highIndex) {
    //check if not base case
    if ((highIndex - lowIndex) >= 1) {
        int middle1 = (lowIndex + highIndex) / 2;
        int middle2 = middle1 + 1;


        mergeSort(array, size, lowIndex, middle1);
        mergeSort(array, size, middle2, highIndex);
        cout << "Calling merge!" << endl;
        merge(array, lowIndex, middle1, middle2, highIndex);
    }
}



int main() {
    const int SIZE = 4;
    int array[SIZE] = { 4,3,2,1 };


    cout << "Array before merge sort: " << endl;
    for (int item : array) {
        cout << item << endl;
    }


    cout << "Array after merge sort" << endl;
    mergeSort(array, SIZE, 0, SIZE - 1);
    for (int item : array) {
        cout << item << endl;
    }