#include <iostream>
#include <string>
using namespace std;

class testClass {
private:
    int d;

public:
    testClass(int a = 1) {
        d = a;
    }

    testClass(testClass &a) {
        d = a.d;
    }

    int getd() {
        return d;
    }
    void copy() {
        testClass b(*this);
        cout << b.getd();
    }
};

template <typename T>
T max(T x, T y) {
    return (x > y) ? x : y;
}

int main() {
    for (int i = 1000; i < 2167; i++) {
        cout << i << endl;
    }


}