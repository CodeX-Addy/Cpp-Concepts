#include <iostream>
using namespace std;

class Base{
    public:
    Base(){
        cout << "Base ctor called.." << endl;
    }
    
    virtual ~Base(){
        cout << "Base dtor called.." << endl;
    }
};

class Derived: public Base{
    public:
    int *arr;
    Derived(){
        cout << "Derived ctor called.." << endl;
        arr = new int[1000];//can results in memory leakage due to heap memory allocation
    }
    
    ~Derived(){
        cout << "Derived dtor called.." << endl;
    }
};

int main() {
    
    Base *b = new Derived();
    delete b;
    return 0;
}
