// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int main() {
    // // int n = 2;
    // int *ptr = nullptr;//wild pointer avoidance
    
    // //void pointer is initializing a pointer with void
    // void *p;
    // // delete(ptr);
    
    // cout << ptr << endl;
  
    // return 0;
    
    //Void pointer implementation
    // void *ptr;
    // int n = 10;
    // ptr = &n;
    // int* p = static_cast<int*>(ptr);//Used to convert the value of one datatype to another. Pointing void pointer into an integer pointer
    // cout << *p;
    
    
    //Dangling pointer 
    int *ptr = new int;
    *ptr = 20;
    cout << *ptr << " " << ptr << endl;;;;;;;;;;;;;
    delete ptr;
    cout << *ptr << endl;;;;;;;;;;;;
    return 0;
}
