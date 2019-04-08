///**********************************************************************************
/// Description: Postfix Calculator
/// Author: Royce Kim
/// COMSC 200 Section 5001
/// Date: April 8, 2019
/// Status : Complete 
///***********************************************************************************
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <iomanip>
#include <sstream>

int stackDisplaySize = 14;

/*
display
*/
void display(std::stack<int> numb, std::queue <char> op) {
    std::string temp;
    std::stringstream ss;

    //display stack
    std::cout << std::right << std::setw(stackDisplaySize);
    if (!numb.empty()) {
        temp +=std::to_string( numb.top() );
        numb.pop();
        while (!numb.empty()) {
            temp += ", ";
            temp += std::to_string(numb.top());
            numb.pop();
        }
    }
    ss >> temp;
    std::cout << temp;
    temp = "";
    
    //display queue
    std::cout << std::right << std::setw(stackDisplaySize*2);
    if (!op.empty()) {
        temp += op.front();
        op.pop();
        while (!op.empty()) {
            temp += ", ";
            temp += op.front();
            op.pop();
        }
    }
    ss >> temp;
    std::cout << temp;
    std::cout << std::endl;
}


/*
validation
*/
int getState(const char& inputChar) {
    std::string numbers = "1234567890";
    std::string operands = "+-/*";
    int state = -1;

    if (numbers.find(inputChar) < numbers.size()) {
        state = 1;
    }
    else if (operands.find(inputChar) < operands.size()) {
        state = 2;
    }
    
    return state;
}


/*----------------
Driver
*/
int main() {
    std::stringstream ss;
    std::string userInput;
    std::stack <int> numbers;
    std::queue <char> items;

    int prev1, prev2;
    int temp = 0;

    //PROMPT
    std::cout << "Enter a postfix expression, Q/q to quit: ";
    std::getline(std::cin, userInput);

    //move inputs to a queue
    for (int i = 0; i < userInput.size(); i++) {
        items.push(userInput.at(i));
    }
    stackDisplaySize = (items.size() < 14)? items.size()*2:28;

    std::cout << std::setw(stackDisplaySize) << std::right << "Operand Stack";
    std::cout << std::setw(stackDisplaySize*2) << std::right << "Postfix Queue" << std::endl;
    //if userinput != q or Q, start pushing to stacks and queues
    for(int i = 0; toupper(userInput.at(0)) != 'Q' && i < userInput.size(); i++) {
        
        //validate inputs
        switch ( getState(userInput.at(i)) ) {

        case 1: //case input's a number
            ss << items.front();
            ss >> temp;
            numbers.push(temp);
            ss.clear();

            items.pop();
            display(numbers, items);
            break;

        case 2: //case if not a number
            prev1 = numbers.top();
            numbers.pop();
            prev2 = numbers.top();
            numbers.pop();

            switch (items.front()) {
            case '+':
                items.pop();
                temp = prev2 + prev1;
                display(numbers, items);
                numbers.push(temp);
                display(numbers, items);
                std::cout << "= " << prev2 << " + " << prev1 << std::endl;
                break;
            case'-':
                items.pop();
                temp = prev2 - prev1;
                display(numbers, items);
                numbers.push(temp);
                display(numbers, items);
                std::cout << "= " << prev2 << " - " << prev1 << std::endl;
                break;
            case'/':
                items.pop();
                temp = prev2 / prev1;
                display(numbers, items);
                numbers.push(temp);
                display(numbers, items);
                std::cout << "= " << prev2 << " / " << prev1 << std::endl;
                break;
            case'*': 
                items.pop();
                temp = prev2 * prev1;
                display(numbers, items);
                numbers.push(temp);
                display(numbers, items);
                std::cout << "= " << prev2 << " * " << prev1 << std::endl;
                break;
            default:
                std::cout << "Invalid Operator" << std::endl;
                break;
            }
            break;  

        case -1:
            std::cout << "Could not recognize: " << userInput.at(i) << std::endl;
            break;

        default:
            break;
        }
    }


    return 0;
}