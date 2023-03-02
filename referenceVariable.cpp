// Reference variables are used to point the same memory location
#include <iostream>
using namespace std;
// Pass by value
void update1(int n){
    n++;
}
// Pass by reference
void update2(int &n){
    n++;
}

int main() {
    int i=5;
    int &j = i;// This is how we're creating the reference variables
    // cout << j << endl;
    cout << i << endl;
    i++;
    cout << i << endl;
    j++;// Updation on value of j will also update the value of i
    cout << i << endl;
    
    // Calling the pass by reference function
    cout << i << endl;
    update2(i); // This will update the value of i
    cout << i << endl;
    
    // Calling the pass by value function
    cout << i << endl;
    update1(i);// Will not update the value of i
    cout << i << endl;
    

    return 0;
}
