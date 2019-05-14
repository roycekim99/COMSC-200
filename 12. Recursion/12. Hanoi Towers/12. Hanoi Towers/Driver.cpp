///**********************************************************************************
/// Description: Hanoi Towers
/// Author: Royce Kim
/// COMSC 200 Section 5001
/// Date: May 2, 2019
/// Status : Complete 
///***********************************************************************************


#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

std::vector<int> a;
std::vector<int> b;
std::vector<int> c;

void display() {
    cout << "src: ";

    for (auto it : a) {
        cout << it << " ";
    }
    cout << " | dest:";
    for (auto it : c) {
        cout << it << " ";
    }
    cout << " | temp:";
    for (auto it : b) {
        cout << it << " ";
    }
    cout << "\n";
}

int pop(int t) {
    int n;

    switch (t) {
    case 1:
        n = a.back(); 
        a.pop_back(); 
        return n;
    case 2:
        n = b.back(); 
        b.pop_back(); 
        return n;
    case 3: 
        n = c.back(); 
        c.pop_back(); 
        return n;
    }
    return 0;
}

void push(int t, int n) {
    switch (t) {
    case 1:
        a.push_back(n);
        break;
    case 2:
        b.push_back(n);
        break;
    case 3:
        c.push_back(n);
        break;
    }
}
void towerOfHanoi(int n, int origin, int destRod, int tempRod) {

    if (n == 1) {
        push(destRod, pop(origin));
        display();
        return;
    }
    towerOfHanoi(n - 1, origin, tempRod, destRod);
    push(destRod, pop(origin));
    display();
    towerOfHanoi(n - 1, tempRod, destRod, origin);
}
// Driver code
int main() {
    string userInput;
    int n = 4; // Number of disks

    cout << "Input number of disks: ";
    getline(cin, userInput);
    stringstream(userInput) >> n;

    for (int i = n; i > 0; i--) {
        a.push_back(i);
    }
    display();
    towerOfHanoi(n, 1, 3, 2); //1,2,3 indicates which vector is pointed

    system("pause");
    return 0;
}