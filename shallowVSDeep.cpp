// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Copy{
    public:
    int x;
    int *y;
    
    Copy(int _x, int _y):x(_x),y(new int(_y)){}//initialisation list
    
    // //default copy ctor --> it will create shallow copy
    // Copy(const Copy&obj){
    //     x = obj.x;
    //     y = obj.y;
    // }
    
    //Copy ctor--> for deep copy
    Copy(const Copy&obj){
        x = obj.x;
        y = new int(*obj.y);
    }
    
    void print(){
        cout << "x is: " << x << endl;
        cout << "y is: " << y << endl;
        cout << "*y is: " << *y << endl;
        cout << endl;
    }
};
int main() {
    
    Copy a(10,20);
    a.print();
    
    Copy b(a);
    b.print();
    
    *b.y = 30;
    b.print();
    a.print();//case of copy ctor
    return 0;
}
