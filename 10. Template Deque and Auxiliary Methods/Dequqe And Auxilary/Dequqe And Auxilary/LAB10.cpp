///**********************************************************************************
/// Description: Lab10a
/// Author: Royce Kim
/// COMSC 200 Section 5001
/// Date: April 20, 2019
/// Status : Complete 
///***********************************************************************************


#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <random>

using namespace std;

class Timer {
    // Type aliases to make accessing nested type easier
    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double, std::ratio<1> >;

    std::chrono::time_point<clock_t> m_beg;

public:
    Timer() : m_beg(clock_t::now()) {}
    void reset() { m_beg = clock_t::now(); }
    double elapsed() const {
        return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
    }
};

void show(vector<int> &num) {
    for (auto i : num) {
        cout << num.at(i) << ", ";
    }

    cout << endl;
}

vector<int> GenerateRandomNumbers(int NumberCount, int minimum, int maximum) {
    random_device rd;
    mt19937 gen(rd());

    vector<int> values(NumberCount);
    uniform_int_distribution<> dis(minimum, maximum);
    generate(values.begin(), values.end(), [&]() { return dis(gen); });
    return values;
}

void insertionSort(vector<int> &listofNum) {

    for (int i = 0; i < listofNum.size() - 1; i++) {

        int j = i + 1;
        int key = listofNum.at(j);
        while (i >= 0 && listofNum.at(i) > key) {
            listofNum.at(i + 1) = listofNum.at(i);
            i--;
        }
        listofNum.at(i + 1) = key;
    }
}

void selectionSort(vector<int> &listofNum) {
    for (int i = 0; i < listofNum.size() - 1; i++) {
        int imin = i;

        for (int j = i + 1; j < listofNum.size(); j++) {
            if (listofNum.at(j) < listofNum.at(imin)) {
                imin = j;

                swap(listofNum.at(i), listofNum.at(imin));
            }
        }
    }
}

int main() {
    const int Size = 10000;

    vector<int> numbersIns;
    vector<int> numbsSel;
    vector<int> comp;

    srand(time(NULL));
    numbersIns = numbsSel = comp = GenerateRandomNumbers(Size, 0, 10000);

    show(numbersIns);
    show(numbsSel);
    show(comp);

    Timer t1;
    insertionSort(numbersIns);
    double run1 = t1.elapsed();
    show(numbersIns);

    Timer t2;
    selectionSort(numbsSel);
    double run2 = t2.elapsed();
    show(numbsSel);

    Timer t3;
    sort(comp.begin(), comp.end());
    double run3 = t3.elapsed();
    show(comp);

    cout << "Insertion Sort Time: " << run1 << " seconds\n"
        << "Selection Sort Time: " << run2 << " seconds\n"
        << "Efficiency for Insertion: " << int(run1 / run3)
        << "Efficiency for Selection: " << int(run2 / run3);

    system("pause");
    return 0;
}