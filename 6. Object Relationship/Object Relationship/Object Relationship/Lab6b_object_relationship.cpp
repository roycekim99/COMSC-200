///**********************************************************************************
/// Description: Contains all 4 pairs of relationships 
/// Author: Royce Kim
/// COMSC 200 Section 5001
/// Date: March 17, 2019
/// Status : Complete 
///***********************************************************************************


#include <iostream>
#include <string>
#include <vector>

using namespace std;

//realization

class Printer {
private:
    string model = "";
    vector<int> inkLevel;

public:
    Printer(string name) : model(name) {}

    string getModel() const { return model; }
    vector<int>* getInkLevels() { return &inkLevel;  }
    friend ostream& operator << (ostream &out, const Printer &rhs);

    virtual void setup() ;
};

class printerSetup : public Printer {
private:
    string name = "badPrinter";

public:
    printerSetup(string n) : name(n), Printer(name) {}

    //realization
    void setup() {
        cout << "setting up" << endl;
    }    
};


//inheritance

class BankAccount {
private:
    string ownerName;
    long balance;

public:
    BankAccount() : ownerName("null"), balance(0) {}
    BankAccount(string n, long bal = 0) : ownerName(n), balance(bal) {}
    
    void setName(string n) { ownerName = n; }
    void setBalance(long amount) { balance = amount;  }

    string getName() const { return ownerName; }
    long getBalance() const { return balance; }

};
class FixedAccount : public BankAccount {
private:
    double interestRate;

public:
    FixedAccount() : BankAccount(), interestRate(0.10) {}
    FixedAccount(string n, long bal = 0, double rate = .1) : BankAccount(n, bal), interestRate(rate) {}

    void setRate(double r) { interestRate = r; }

    double getRate() const { return interestRate; }

};

//composition

class Books {
private:
    string title;
    int pageCount;

public:
    Books(string t = "null", int p = 0) : title(t), pageCount(p){}

    void setTitle(string input) { title = input; }
    void setPages(int i) { pageCount = i; }
    
    string getTitle() const { return title; }
    int getPageCount() const { return pageCount; }

};

class Library {
private:
    string name;
    //composition
    vector <Books> books;

public:
    Library(string n = "none") : name(n) {}
    Library(string n , vector<Books> stash) : name(n) , books(stash) {}

    Books* getBook(int i) { return &books.at(i); }
    int getBookCount() const { return books.size(); }
    string getName() const { return name; }

    void setName(string n) { name = n; }
    void replaceLibrary( vector<Books> &b) { books = b; }

};

//aggregation

class Booksa {
private:
    vector <string > listOfTitles;

public:
    Booksa() : listOfTitles(NULL) {}
    Booksa(string title) { listOfTitles.push_back(title); }
    Booksa(vector <string> &list) : listOfTitles(list) {}

    void setList(vector<string> &list) { listOfTitles = list; }
    
    vector<string> *getList() { return &listOfTitles; }

};

class Librarya {
private:
    string name;
    //aggregation
    Booksa *books;

public:
    Librarya(string n = "none") : name(n) {}
    Librarya(string n, Booksa &stash) : name(n) { *books = stash; }

    Booksa* getBook(int i) { return books; }
    int getBookCount() const { return books->getList()->size(); }
    string getName() const { return name; }

    void setName(string n) { name = n; }
    void replaceLibrary(Booksa &b) { *books = b; }

};

int main() {}