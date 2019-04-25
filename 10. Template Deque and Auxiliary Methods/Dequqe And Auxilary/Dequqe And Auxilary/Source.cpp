#include<iostream>
#include <chrono>
#include <deque>

using namespace std;

class Timer {
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


// Node of a doubly linked list
template<class T>
class Node {
public:
    T data;
    Node<T> *prev, *next;
    static Node<T>* getnode(int data) {
        Node<T>* n = new Node<T>;
        n->data = data;
        n->prev = n->next = nullptr;
        return n;
    }
};

// A doubly linked list deque
template<class T>
class Deque {
    Node<T> *head, *tail, *copy;
    int size;

    // deep copy helper
    void deepCopy(const Deque<T> & rhs);
public:
    Deque() :head(nullptr), tail(nullptr), size(0) {}
    Deque(const Deque<T> & rhs) {
        deepCopy(rhs);
    } // copy constructor

    Deque(Deque<T> && rhs) {
        size = rhs.size;
        rhs.size = 0;
        head = rhs.head;
        rhs.head = nullptr;
        tail = rhs.tail;
        rhs.tail = nullptr;

    }

    Deque<T> & operator= (Deque<T> & rhs) {
        if (this == &rhs) {
            return *this;
        }

        erase();
        deepCopy(rhs);

        return *this;
    } // copy operator=

    Deque<T> & operator= (Deque<T> && rhs) {
        // Self-assignment detection
        if (&rhs == this)
            return *this;

        // Release any resource we're holding
        erase();

        // Transfer ownership of a.m_ptr to m_ptr
        size = rhs.size;
        rhs.size = 0;
        head = rhs.head;
        rhs.head = nullptr;
        tail = rhs.tail;
        rhs.tail = nullptr;

        return *this;
    } // move operator=

    // Operations on Deque
    void pushHead(T data);
    void pushTail(T data);
    void popHead();
    void popTail();

    void erase();
    T getFront();
    T getRear();
    int _size() { return size; }
    bool isEmpty() { return !head; }

    T& operator[] (const int &sub) {
        if (size == 0) { return size; } //Empty deque
        Node<T>* temp = head;
        for (int i = 0; i < sub; i++) {
            temp = temp->next;
            if (temp == NULL)
                return size;
        }
        // temp = temp->next;
        return temp->data;
    }

};

template<class T>
void Deque<T>::deepCopy(const Deque<T> & rhs) {
    Node<T> *newNode = new Node<T>;
    Node<T> *current = rhs.head; //current points to the list to be copied
    size = rhs.size;//copy the head node
    head = newNode; //create the node
    head->data = current->data; //copy the info
    head->next = current->next; //set the link field of the node to nullptr
    head->prev = current->prev;
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

template <class T>
void Deque<T>::pushHead(T data) {
    Node<T> *newNode = nullptr;

    newNode = new Node<T>;
    newNode->data = data;
    newNode->next = nullptr;

    if (head == NULL)
        tail = head = newNode;

    // Inserts node at the front end
    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    size++;
}

template <class T>
void Deque<T>::pushTail(T data) {
    Node<T>* newNode = Node<T>::getnode(data);

    if (tail == NULL)
        head = tail = newNode;

    // Inserts node at the rear end
    else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

template <class T>
void Deque<T>::popHead() {

    Node<T>* temp = head;
    head = head->next;

    // If only one element was present
    if (head == NULL)
        tail = NULL;
    else
        head->prev = NULL;
    free(temp);

    size--;

}

template <class T>
void Deque<T>::popTail() {
    Node<T>* temp = tail;
    tail = tail->prev;

    // If only one element was present
    if (tail == NULL)
        head = NULL;
    else
        tail->next = NULL;
    free(temp);

    size--;
}

template <class T>
T Deque<T>::getFront() {
    if (isEmpty())
        return 0;
    return head->data;
}

template <class T>
T Deque<T>::getRear() {
    if (isEmpty())
        return 0;
    return tail->data;
}

template <class T>
void Deque<T>::erase() {
    tail = NULL;
    while (head != NULL) {
        Node<T>* temp = head;
        head = head->next;
        free(temp);
    }
    size = 0;
}

// Driver program to test the Link List Deque class
int main() {
    Deque<int> dq;
    cout << "\nInsert item '5' at tail";
    dq.pushTail(5);

    cout << "\nInsert item '10' at tail";
    dq.pushTail(10);
    cout << "\nRear item: " << dq.getRear();

    dq.popTail();
    cout << "\nAfter deleting tail item, new tail is "
        << dq.getRear();

    cout << "\nInserting item '15' in head";
    dq.pushHead(15);
    cout << "\nFront item: " << dq.getFront()
        << "\nNumber of items in Deque: " << dq._size();

    dq.popHead();
    cout << "\nAfter deleting head item new head is "
        << dq.getFront();

    dq.popHead();
    cout << "\nAfter deleting head item new head is "
        << dq.getFront();

    cout << "\nInitializing a 10000 item Deque.";
    Timer t1;
    for (int i = 1; i <= 10000; i++) {
        dq.pushTail(i);
    }

    cout << "\nAdd 1~10000, dq now has "
        << dq._size() << " items.";
    double run1 = t1.elapsed();
    cout << "\nTime elipsed: " << run1 << " seconds";

    Timer t2;
    cout << "\nDeep Copy construct dq2";
    Deque<int> dq2(dq);
    double run2 = t2.elapsed();
    cout << "\nTime elipsed: " << run2 << " seconds"
        << "\ndq2 front to rear: " << dq2.getFront()
        << " to " << dq2.getRear();

    cout << "\nMove construct dq3";
    Timer t3;
    Deque<int> dq3(std::move(dq));
    double run3 = t3.elapsed();
    cout << "\nTime elipsed: " << run3 << " seconds"
        << "\ndq3 front to rear: " << dq3.getFront()
        << " to " << dq3.getRear();

    cout << "\ndq2[0] is " << dq2[0]
        << ", dq2[999] is " << dq2[999] << endl;
}