#include <iostream>
using namespace std;

class A{
    int x;
    
    public:
    A(int _x):x(_x){}
    int getX() const{ return x;}
    void setX(int _x){ x = _x; }
    
    friend class B;
    friend void print(const A &);
};

class B{
    public:
    void print(const A&a){
        cout << a.x << endl;
        cout << "Inside class" << endl;
    }
};

void print(const A&a){
    cout << a.x << endl;
}

int main() {
    A a(20);
    cout << a.getX() << endl;
    B obj;
    obj.print(a);
    return 0;
}
