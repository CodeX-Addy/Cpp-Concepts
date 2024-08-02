#include <iostream>
using namespace std;

void update(int **p){
    **p = **p + 1;
}

int main() {
    int a = 5;
    int *p = &a;
    int **p2 = &p;
    cout << "Before-->" << endl;
    cout << a << endl;
    cout << p << endl;
    cout << p2 << endl;
    update(p2);
    
    cout << "After-->" << endl;
    cout << a << endl;
    cout << p << endl;
    cout << p2 << endl;

    return 0;
}

// Output
// Before-->
// 5
// 0x7ffd4f72d5a4
// 0x7ffd4f72d5a8
// After-->
// 6
// 0x7ffd4f72d5a4
// 0x7ffd4f72d5a8
// The address values could be different in ur compiler
