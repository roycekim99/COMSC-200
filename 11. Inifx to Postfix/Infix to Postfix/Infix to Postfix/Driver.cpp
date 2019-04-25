/* C++ implementation to convert infix expression to postfix*/
// Note that here we use std::stack  for Stack operations 
#include <string>
#include <stack>
#include <queue>
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

int stackDisplaySize = 14;

void display(std::stack<char> operators, string pstfx) {
    string op = "";
    
    cout << "Operator: " << setw(operators.size()) << left;
    
    for (int i = 0; i < operators.size(); i++) {
        op += operators.top();
        operators.pop();
    }
    cout << op << "\tOutput: " << setw(pstfx.size()) << pstfx << endl;
}


//Function to return precedence of operators 
int prec(char c) {
    switch (c) 
    {
    case '^':
        return 3;
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return -1;
        break;
    }
}

// The main function to convert infix expression 
//to postfix expression 
std::string infixToPostfix(string s) {
    std::stack<char> st;

    int l = s.length();
    string postfix;

    for (int i = 0; i < l; i++) {
        if ((s[i] >= 'a' && s[i] <= 'z') || 
            (s[i] >= 'A' && s[i] <= 'Z') || 
            (s[i] >= '0' && s[i] <= '9')) {    // If the scanned character is an operand, add it to output string. 
            postfix += s[i];
        }  
        else if (s[i] == '(') {                 // If the scanned character is an ‘(‘, push it to the stack. 
            st.push(s[i]);
        }
        else if (s[i] == ')') {                 // if ')', pop till ‘(‘ is encountered.             
         
            while (st.size() && st.top() != '(') {
                char c = st.top();
                st.pop();
                postfix += c;
            }
            while (st.size() && st.top() == '(' ) {
                char c = st.top();
                st.pop();
            }
        } 
        else if(prec(s[i]) > 0){                //If operator
            while (st.size() > 0 &&             //check to see if stack is empty
                (prec(s[i]) < prec(st.top()))) //continue to add to postfix until stack has higher prec val
            {
                char c = st.top();
                st.pop();
                postfix += c;
            }
            st.push(s[i]);
        }
        display(st, postfix);

    }
    //Pop all the remaining elements from the stack 
    while (st.size()) {
        char c = st.top();
        st.pop();
        postfix += c;
    }

    cout << postfix << endl;
    return postfix;

}

/*
display
*/
void display(std::stack<int> numb, std::queue <char> op) {
    std::string temp;
    std::stringstream ss;

    //display stack
    std::cout << std::right << std::setw(14);
    if (!numb.empty()) {
        temp += std::to_string(numb.top());
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
    std::cout << std::right << std::setw(stackDisplaySize * 2);
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
    std::string operands = "+-/*^";
    int state = -1;

    if (numbers.find(inputChar) < numbers.size()) {
        state = 1;
    }
    else if (operands.find(inputChar) < operands.size()) {
        state = 2;
    }

    return state;
}

void calculateInput(string userInput) {
    std::stringstream ss;
    std::stack <int> numbers;
    std::queue <char> items;

    int prev1, prev2;
    int temp = 0;

    //move inputs to a queue
    for (int i = 0; i < userInput.size(); i++) {
        items.push(userInput.at(i));
    }
    stackDisplaySize = (items.size() < 14) ? items.size() * 2 : 28;

    std::cout << std::setw(stackDisplaySize) << std::right << "Operand Stack";
    std::cout << std::setw(stackDisplaySize * 2) << std::right << "Postfix Queue" << std::endl;
    //if userinput != q or Q, start pushing to stacks and queues

    for (int i = 0; toupper(userInput.at(0)) != 'Q' && i < userInput.size(); i++) {

        //validate inputs
        switch (getState(userInput.at(i))) {

        case 1: //case input's a number
        {
            ss << items.front();
            ss >> temp;
            numbers.push(temp);
            ss.clear();

            items.pop();
            break;
        }
        case 2: //case if not a number
        {
            prev1 = numbers.top();
            numbers.pop();
            prev2 = numbers.top();
            numbers.pop();

            switch (items.front()) {
            case '^':
                items.pop();
                temp = prev2 * prev1;
                numbers.push(temp);
                std::cout << "= " << prev2 << " ^ " << prev1 << std::endl;
            case '+':
                items.pop();
                temp = prev2 + prev1;
                numbers.push(temp);
                std::cout << "= " << prev2 << " + " << prev1 << std::endl;
                break;
            case'-':
                items.pop();
                temp = prev2 - prev1;
                numbers.push(temp);
                std::cout << "= " << prev2 << " - " << prev1 << std::endl;
                break;
            case'/':
                items.pop();
                temp = prev2 / prev1;
                numbers.push(temp);
                std::cout << "= " << prev2 << " / " << prev1 << std::endl;
                break;
            case'*':
                items.pop();
                temp = prev2 * prev1;
                numbers.push(temp);
                std::cout << "= " << prev2 << " * " << prev1 << std::endl;
                break;
            default:
                break;
            }
            break;
        }

        case -1:
            std::cout << "Could not recognize: " << userInput.at(i) << std::endl;
            break;

        default:
            break;
        }
    }
}

//Driver program to test above functions 
int main() {
    string exp;
    
    cout << "Enter an expression: ";
    getline(cin, exp);

    calculateInput(infixToPostfix(exp));

    return 0;
}
// This code is contributed by Gautam Singh
