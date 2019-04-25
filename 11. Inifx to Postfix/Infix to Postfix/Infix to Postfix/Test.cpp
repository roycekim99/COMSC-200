
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#define MIN -99999
using namespace std;

string infix; // infix notation
string postfix; // postfix notation
int stack[50]; // stack to use
int i, top = -1; // stack pointer
int j = 0; // postfix queue pointer
int incoming; // priority of incoming symbol
int in_stack; // priority of symbol inside the stack(top element)
int step = 1; // counter to display steps

// returns true of c is a digit [0-9]
bool isDigit(char c) {
    if (c <= '9' && c >= '0') return true;
    return false;
}

// returns true if c is an operand [0-9]
bool isOperand(char C) {
    if (C >= '0' && C <= '9') return true;
    return false;
}

// given an integer, returns corresponding ascii value
char getChar(int i) {
    if (i <= 9 && i >= 0)
        return ((char)(i + 48));
    return (char)i;
}

// given a character, returns its integer value
// but for numbers, [0-9], they are returned as numbers
int getInt(char i) {
    if (isDigit(i))
        return ((i - 48));
    return (int)i;
}

// is stack empty?
bool isEmpty() {
    return top < 0;
}

// push into stack
void spush(int ele) {
    top++;
    stack[top] = ele;
}

// peek element of stack
int speek() {
    if (isEmpty()) return MIN;
    return stack[top];
}

// pop from stack
int spop() {
    if (isEmpty()) return MIN;
    int ele = speek();
    top--;
    return ele;
}

// returns the priority of the character in the expression
int priority_of_char(char c, int q) {

    switch (c) {
        // + and - has priority 1, both instack and incoming priority
    case '+':
    case '-': return 1;
        // * and / has priority 2, both instack and incoming priority
    case '/':
    case '*': return 2;
        // ^(power) has priorty 3, both instack and incoming priority
    case '^': return 3;
        // ( has , instack priority 0 and incoming priority 4
    case '(': return((q == 1) ? 4 : 0);
    case ')': return 8;
    default: if (isOperand(c))
        return 9;
             else {
        cout << "p :" << c;
        cout << "\n GIVEN EXPRESSION IS INVALID";
    }
    }
}

// print stack and queue
void printState() {
    cout << "\nOP Stack : ";
    for (int i = 0; i <= top; i++)
        cout << getChar(stack[i]);
    cout << "Postfix Queue : ";
    for (int i = 0; i < j; i++)
        cout << postfix[i];
}

void fun() {
    // if instack priority is greater than incoming priority
    // then push the incoming symbol to the stack
    if (incoming >= in_stack)
        spush(getInt(infix[i]));
    // else pop the top symbol in stack repeatedly and
    // until the condition incoming > in_stack is met
    // then push incoming symbol to the stack
    else {
        int op = speek();
        while (incoming <= in_stack) {
            spop();
            postfix[j++] = getChar(op);
            op = speek();
            in_stack = priority_of_char(speek(), 2);
        }
        spush(getInt(infix[i]));
    }
}

void infix_to_postfix() {
    int len_a = infix.length();

    for (i = 0; i < len_a; i++) {
        // calculate instack and incoming symbol priorities
        incoming = priority_of_char(infix[i], 1);
        in_stack = isEmpty() ? 0 : priority_of_char(speek(), 2);

        switch (incoming) {
        case 1:
        case 2:
        case 3:fun();
            break;
        case 4:spush(getInt(infix[i]));
            break;
        case 8: while (getChar(speek()) != '(') {
            postfix[j] = getChar(spop());
            j++;
        }
                spop();
                break;
                // 9 is for operands, you can give any number other than 1,2,3,4
                // but don't forget to return the same from priority_of_char function
        case 9: postfix[j++] = infix[i];
            break;
        }
        printState();
    }
    while (!isEmpty()) {
        int ele = spop();
        if (ele != '(')
            postfix[j++] = getChar(ele);
    }
}

void preference() {
    int opr1, opr2;

    if (isDigit(postfix[i])) // if postfix[i] is a digit push it into stack
        spush(getInt(postfix[i]));
    else { // else if it is a symbol then perform the operation
        cout << "\nStep " << (step) << ": ";
        opr1 = spop();
        opr2 = spop();
        switch (getChar(postfix[i])) {
        case '+':cout << opr2 << " + " << opr1 << " = " << (opr1 + opr2) << endl;
            spush(opr1 + opr2);
            break;
        case '-':cout << opr2 << " - " << opr1 << " = " << (opr2 - opr1) << endl;
            spush(opr2 - opr1);
            break;
        case '*':cout << opr2 << " * " << opr1 << " = " << (opr1 * opr2) << endl;
            spush(opr1*opr2);
            break;
        case '/':cout << opr2 << " / " << opr1 << " = " << (opr2 / opr1) << endl;
            spush(opr2 / opr1);
            break;
        case '^':cout << opr2 << " ^ " << opr1 << " = " << pow(opr2, opr1) << endl;
            spush(pow(opr2, opr1));
            break;
        default:cout << "Invalid postfix notation given\n symbol " << (postfix[i]);
            exit(0);
        }
        step++;
    }
}

void postfix_eval() {
    // 21-22^3^*84/+
    int len_a = j;
    for (i = 0; i < len_a; i++) {
        preference();
        //printState(); to print up to date stack and queue info
    }
    cout << "\nValue : " << speek();
}

int main() {
    cout << "Enter the infix notation:\n";
    getline(cin, infix);

    infix_to_postfix();
    printState();
    cout << "\nPostfix => " << postfix;
    postfix_eval();
}