#include <iostream>
using namespace std;

void print(int *p){
    cout << *p << endl;
    cout << p << endl;
}

void update(int *p){
    p = p + 1;// Will give the same address without updation
    *p = *p + 1; // Will increment the value by 1
}
    
int main() {
    int a = 5;
    int *p = &a;
    
    print(p);
    // cout << a << endl;
    // cout << &a << endl;

    return 0;
}
