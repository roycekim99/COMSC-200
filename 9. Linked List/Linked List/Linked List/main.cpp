///**********************************************************************************
/// Description: Driver class for Linked List
/// Author: Royce Kim
/// COMSC 200 Section 5001
/// Date: April 15, 2019
/// Status : Complete 
///***********************************************************************************


#include "Linked List.cpp"
#include <vector>
#include <string>
#include <sstream>

void menu() {
    std::cout << "--- \t AS9 LinkedList Test Menu\t ---" << endl
        << "\t" << "N - to bulk create New Queue" << endl
        << "\t" << "D - to Display" << endl
        << "\t" << "E - is Empty?" << endl
        << "\t" << "A - to Add ~ push front" << endl
        << "\t" << "a - to append ~ push back" << endl
        << "\t" << "R - to Remove ~ pop front" << endl
        << "\t" << "r - to Remove ~ pop back" << endl
        << "\t" << "L - length of Queue" << endl
        << "\t" << "C - to Clear" << endl
        << "\t" << "Q - to Quit this program" << endl
        << "\t" << "H - this menu" << endl;


}

int main() {
    string token;
    string catchVar; // To hold values popped off the Queue
    string choice; // user input for choices
    string str; // user input for list, delimiter, ...

    int pos;
    int Queue_size;
    int item;

    stringstream sst;
    stringstream ss;

    bool stay = true;

    IntLinkedQueue<int> q;

    // create one instance for each of the test classes
    std::cout << "\nInstanciate an object of Queue\n";

    std::cout << "\nFirst, test with hard-wired data sets!\n"
        << "For example, \nyou may use one set of tokens for all test classes: \n";

    int s[] = { 1, 3, 5, 7, 9 };
    vector<int> input1(s, end(s));

    // show the initial item list
    int input_size = input1.size();
    for (auto item : input1) {
        std::cout << item << ((input_size <= 1) ? " " : ", ");
        input_size--;
    }
    std::cout << endl;

    // initialize the Queue class instances
    for (auto i : input1) q.addToList(i);
    std::cout << "\nUse menu to test a Queue class instance.\n";
    menu();

    // main menu while
    string input;

    while (stay) {  // main menu while starts
        std::cout << "\n	Enter your command: ";
        stay = true;
        cin >> choice;


        cin.ignore();

        if (choice.size() == 1) {
            char ch = choice[0];
            string value;
            switch (ch) {  // main menu switch starts
            case 'N':
            case 'n':
            {
                if (!q.isEmpty()) q.clear();

                std::cout << "Enter a line of comma (,) delmited data set: ";
                getline(cin, input);  			// user input -> string
                ss << input;			// string -> stream
                while (getline(ss, token, ',')) {	// stream -> string token
                    stringstream sst(token);
                    sst >> item;
                    q.addToList(item);
                }
                cout << endl;
                break;

            }
/*            case 'I':
            {
                std::cout << "Enter the 0-based index: ";
                cin >> pos;
                if (pos > -1 && pos < q.size()) {
                    char temp;
                    std::cout << "The Queue[" << pos << "] is " << q.at(pos);
                    std::cout << endl << "To modify y/n? ";
                    cin >> temp;
                    switch (temp) {
                    case 'Y':
                    case 'y':
                        std::cout << "What is the new number? ";
                        cin >> item;
                        q.insertNode(item, pos);
                        q.removeNode(pos + 1);
                        break;
                    }
                    break;
                }
            }*/
            case 'd':
            case 'D':   //display
                q.print();
                cout << endl;
                break;
            case 'e':
            case 'E':   //check if empty
                std::cout << "Is the list empty? " << ((q.isEmpty()) ? "yes" : "no") << endl;
                std::cout << endl;
                break;
            case 'A':   //add to list ~ push front
                std::cout << "Enter a number: ";
                cin >> item;
                std::cout << "You entered: " << item << endl;
                q.insertNode(item, 0);
                cout << "Queue: ";
                q.print();
                cout << endl;
                break;
            case 'a':   //append ~ push back
                std::cout << "Enter a number: ";
                cin >> item;
                std::cout << "You entered: " << item << endl;
                q.addToList(item);
                cout << "Queue: ";
                q.print();
                std::cout << endl;
                break;
            case 'R':   //remove ~ pop front
                std::cout << "Removed " << q.at(0) << endl;
                q.removeNode(0);
                cout << "Queue: ";
                q.print();
                std::cout << endl;
                break;
            case 'r':   //remove ~ pop back
                std::cout << "Removed " << q.at(q.size()-1) << endl;
                q.removeNode(q.size()-1);
                cout << "Queue: ";
                q.print();
                std::cout << endl;
                break;
            case 'l':
            case 'L':   //check length of queue
                cout << "\tNumber of Entries in Queue: " << q.size() << endl;
                break;
            case 'c':
            case 'C':   //clear list
                cout << "Queue is cleared." << endl;
                q.clear();
                break;
            case 'q':
            case 'Q':   //quit program
                stay = false;
                break;
            case 'H':   //refresh main menu 
                menu();
                break;
            }
        }

    }
    return 0;
}
