///**********************************************************************************
/// Description: Linked List Class
/// Author: Royce Kim
/// COMSC 200 Section 5001
/// Date: April 15, 2019
/// Status : Complete 
///***********************************************************************************

#ifndef DEQUE
#define DEQUE
#include <iostream>

using namespace std;

// Node of a doubly linked list 
template<class T>
class Node {
public:
    T data;
    Node<T> *prev, *next;

    Node<T>() {
        prev = nullptr;
        next = nullptr;
    }
    static Node<T>* getnode(int data) {
        Node<T>* n = new Node<T>;
        n->data = data;
        n->prev = n->next = nullptr;
        return n;
    }
};


//linked list class
template <class T>
class Deque {

private:
    Node<T>* head;
    Node<T>* tail;
    int listSize = 0;

public:

    Deque() : head(nullptr), tail(nullptr), listSize(0) {}

    Deque(const Deque<T> & rhs) {   // copy constructor
        head = rhs.get;
        tail = rhs.tail;
        listSize = rhs.size();
    }

    Deque(Deque<T> && rhs) {		// move constructor
        while (!rhs->isEmpty()) {
            pushTail(rhs->getFront());
            rhs->popHead();
        }
    }

    ~Deque() {
        Node<T> *next = head;
        while (next) {
            Node<T> *deleteMe = next;
            next = next->next;
            delete deleteMe;
        }
    }

    int size() {
        return listSize;
    }

    void addToList(T val) { //push back
        Node<T>* temp = new Node<T>;
        temp->value = val;
        temp->nextNode = nullptr;

        if (head == nullptr) { //if nothing in the list
            head = temp;
            tail = temp;
            temp = nullptr;
        }
        else {
            tail->nextNode = temp;
            tail = temp;
        }

        listSize++;
    }

    void print() {
        Node<T>* printNode = head;

        while (printNode) {
            cout << printNode->value << ", ";
            printNode = printNode->nextNode;
        }

    }

    int searchList(T searchVal) {
        Node<T>* scanNode = head;
        int pos = -1;
        bool isFound = false;

        while (scanNode && !isFound) {
            isFound = scanNode->value == searchVal;
            scanNode = scanNode->nextNode;
            ++pos;
        }

        return (isFound) ? pos : -1;
    }

    T operator[] (const int &pos) {
        Node<T>* scanningNode = head;

        for (int i = 0; i < pos && pos < listSize; ++i) {
            scanningNode = scanningNode->next;
        }

        return scanningNode->data;
    }

    //get val at
    T at(int pos) {
        Node<T>* scanningNode = head;

        for (int i = 0; i < pos && pos < listSize; ++i) {
            scanningNode = scanningNode->next;
        }

        return scanningNode->value;
    }

    //int val
    void insertNode(int val, int pos = 0) {
        Node<T>* temp = new Node<T>;
        Node<T>* prev = new Node<T>;
        Node<T>* scanNode = head;   //start scan at beginning

        temp->data = val;
        
        if (pos == 0 && listSize > 1) { //insert at beginning
            if (!head) {    //if list is blank
                head = temp;
            }
            else {
                temp->next = head;
                head = temp;
            }
        }
        else if (pos == listSize - 1) { //end of list
            if (!tail) {    //if tail DNE (aka. empty list)
                tail = temp;
                head = temp;
            }
            else {
                tail->next = temp;
                temp->prev = tail;
                tail = temp;
            }
        }
        else if (pos && pos < listSize - 1) {
            //find position
            for (int i = 0; i < pos; ++i) {
                prev = scanNode;
                scanNode = scanNode->next;//scan to next
            }
            prev->next = temp;
            temp->next = scanNode;
        }
        
        listSize++;
    }

    //actual node
    void insertNode(Node<T> inputNode, int pos = 0) {
        Node<T>* temp = inputNode;
        Node<T>* prev = new Node<T>;
        Node<T>* scanNode = head;//start scan at beginning

        //if insert at head
        if (pos == 0) {
            inputNode.nextNode = head;
            head = inputNode;
            listSize++;
        }
        else if (pos == listSize - 1) {
            inputNode.nextNode = nullptr;
            tail = inputNode;
            listSize++;
        }
        else {
            //find position
            for (int i = 0; i < pos; ++i) {
                prev = scanNode;
                scanNode = scanNode->nextNode;
            }
            prev->nextNode = inputNode;
            inputNode.nextNode = scanNode;

            listSize++;
        }

    }

    void copyTo(Deque &destination) {
        Node<T>* currentNode = head;

        while (currentNode) {
            destination.addToList(currentNode->value);
            currentNode = currentNode->nextNode;
        }
    }

    void reverse() {
        Node<T>* scanningNode = head;
        Node<T>* prevNode = nullptr;
        Node<T>* nextNode = nullptr;

        while (scanningNode) {

            nextNode = scanningNode->nextNode; //reserve pointer address to the next node

            scanningNode->nextNode = prevNode;//point current node to previous node

            prevNode = scanningNode; //set prevNode to current node, prep for next runthrough
            scanningNode = nextNode; //scan to next node
        }
        head = prevNode;
    }

    void removeNode(int pos) {
        Node<T>* scannerNode = head;
        Node<T>* prevNode = new Node<T>;

        if (listSize == 1) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            //remove head
            if (pos == 0) {
                if (listSize > 1) {
                    tail->prev = nullptr;
                    head = tail;
                }
                delete head;
                head = scannerNode->next;

            }
            else {//find position
                for (int i = 0; i < pos; ++i) {
                    prevNode = scannerNode;
                    scannerNode = scannerNode->next;
                }
            }

            //remove position
            if (pos == (listSize - 1)) {
                tail = prevNode;
                prevNode->next = nullptr;
            }
            else {
                prevNode->next = scannerNode->next;
            }
            
        }
        if (listSize > 0) listSize--;
    }

    bool isEmpty() {
        return (listSize == 0);
    }

    void clear() {
        Node *next = head;
        while (next) {
            Node *deleteMe = next;
            next = next->next;
            delete deleteMe;
        }
        listSize = 0;
    }

    Deque<T> & operator= (Deque<T> & rhs); // copy operator=
    Deque<T> & operator= (Deque<T> && rhs); // move operator=

    // Operations on Deque 
    void pushHead(T data) {
        Node<T>* temp = new Node<T>;

        temp->data = data;

        if (listSize == 0) {    //if head is null
            temp->next = head->next;
            head = temp;
            tail = head;
        }
        else if (listSize == 1) {
            temp->next = tail;
            head = temp;
            tail->prev = head;
        }
        else {  //if head exists
            temp->next = head;
            head->prev = temp;

            head = temp;
        }
        listSize++;

    }
    void pushTail(T data) {
        Node<T>* temp = new Node<T>;
        temp->data = data;

        if (listSize == 0) {    //if head is null
            head = temp;
            tail = head;
        }
        else if (listSize == 1) {
            head->next = temp;
            tail = temp;
            tail->prev = head;
        }
        else {  //if head exists
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
        }
        listSize++;
    }

    void popHead() {
        Node<T>* temp = head;
        head = head->next;

        if (head==NULL) {
            tail = nullptr;
        }
        else {
            head->prev = nullptr;
        }
        delete temp;

        listSize--;
    }
    void popTail() {
        Node<T>* temp = tail;
        tail = tail->prev;

        if (!tail) {
            head = nullptr;
        }
        else {
            tail->next = nullptr;
        }
        free(temp);

        listSize--;
    }

    void erase() {
        Node *next = head;
        while (next) {
            Node *deleteMe = next;
            next = next->next;
            delete deleteMe;
        }
        listSize = 0;
    }

    T getFront() {
        if (isEmpty()) {
            cout << endl << "no items" << endl;
            return -1;
        }
        else {
            return head->data;
        }
    }
    T getRear() {
        if (isEmpty()) {
            cout << endl << "no items" << endl;
            return -1;
        }
        else {
            return tail->data;
        }
    }

    int _size() { return listSize; }



    template<class T>
    void deepCopy(const Deque<T> & rhs) {
        Node<T> *newNode = new Node<T>;
        Node<T> *current = rhs.head; //current points to the list to be copied
        size = rhs.size;//copy the head node
        copy = newNode; //create the node
        copy->data = current->data; //copy the info
        copy->next = current->next; //set the link field of the node to nullptr
        copy->prev = current->prev;
        tail = head; //make tail point to the head node

        current = current->next; //make current point to the next node
        //copy the remaining list
        while (current != nullptr) {
            newNode = new Node<T>; //create a node
            newNode->data = current->data; //copy the info
            newNode->next = current->next;
            newNode->prev = current->prev;
            tail->next = newNode;
            tail = newNode;
            current = current->next;
        }
    }
    // complete the rest of definitions below
};

#endif // !DEQUE
