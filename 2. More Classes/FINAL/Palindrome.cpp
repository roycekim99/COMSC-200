///**********************************************************************************
/// Description: Checks user inputs to see if it is a palindrome
/// Author: Royce Kim
/// COMSC 200 Section 5001
/// Date: Feb. 9, 2019
/// Status : Complete 
///***********************************************************************************

#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const std::string &input) {
    if (input.length() <= 1) {
        return true;
    }
    else if (input.at(0) != input.at(input.length() - 1)) {
        return false;
    }
    else {
        return isPalindrome(input.substr(1, input.length() - 2));
    }
}


int main() {
    string testStrings[6] =
    { "ABLE WAS I ERE I SAW ELBA",
      "FOUR SCORE AND SEVEN YEARS AGO",
      "NOW IS THE TIME FOR ALL GOOD MEN",
      "DESSERTS I STRESSED",
      "ASK NOT WHAT YOUR COUNTRY CAN DO FOR YOU",
      "KAYAK" };
    for (int i = 0; i < 6; i++) {
        cout << "\033[0m" << testStrings[i] << ": " << (isPalindrome(testStrings[i]) ? "\033[1;32mIs palindrome" : "\033[0;31mIs not palindrome") << endl;
    }
}