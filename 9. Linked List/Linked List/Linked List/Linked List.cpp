///**********************************************************************************
/// Description: Linked List Class
/// Author: Royce Kim
/// COMSC 200 Section 5001
/// Date: April 15, 2019
/// Status : Complete 
///***********************************************************************************

#ifndef INTLINKEDQUEUE
#define INTLINKEDQUEUE
#include <iostream>

using namespace std;


//node struct
template <class T>
struct Node {
    T value;
    Node *nextNode;
};


//linked list class
template <class T>
class IntLinkedQueue {

private:
    Node<T>* head;
    Node<T>* tail;
    int listSize = 0;

public:

    IntLinkedQueue() {
        head = nullptr;
        tail = nullptr;
    }

    ~IntLinkedQueue() {
        head = nullptr;
        tail = nullptr;
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

    //get val at
    T at(int pos) {
        Node<T>* scanningNode = head;

        for (int i = 0; i < pos && pos < listSize; ++i) {
            scanningNode = scanningNode->nextNode;
        }

        return scanningNode->value;
    }

    //int val
    void insertNode(int val, int pos = 0) {
        Node<T>* temp = new Node<T>;
        Node<T>* prev = new Node<T>;
        Node<T>* scanNode = head;//start scan at beginning

        temp->value = val;

        if (pos && pos <= listSize) {

            //find position
            for (int i = 0; i < pos; ++i) {
                prev = scanNode;
                scanNode = scanNode->nextNode;//scan to next
            }
            prev->nextNode = temp;
            temp->nextNode = scanNode;
        }
        else if (pos == 0) { //insert at beginning
            temp->nextNode = head;
            head = temp;
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

    void copyTo(IntLinkedQueue &destination) {
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

        //remove head
        if (pos == 0) {
            head = nullptr;
            head = scannerNode->nextNode;
            
        }
        else {//find position
            for (int i = 0; i < pos; ++i) {
                prevNode = scannerNode;
                scannerNode = scannerNode->nextNode;
            }
        }
        //remove position
        if (pos == (listSize - 1)) {
            tail = prevNode;
            prevNode->nextNode = nullptr;
        }
        else {
            prevNode->nextNode = scannerNode->nextNode;
        }
        if (listSize > 0) listSize--;
    }

    bool isEmpty() {
        return (listSize == 0);
    }
    void clear() {
        head = nullptr;
        tail = nullptr;
        listSize = 0;
    }


};

#endif // !INTLINKEDQUEUE

