#include <iostream>
using namespace std;

int main() {
    int i = 5;
    int *p = &i;
    int **p2 = &p;
    // If we want to print the content of i then there are 3 ways
    cout << i << endl;
    cout << *p << endl;
    cout << **p2 << endl;
    // Now printing the address of i
    cout << &i << endl;
    cout << p << endl;
    cout << *p2 << endl;
    
    return 0;
}
