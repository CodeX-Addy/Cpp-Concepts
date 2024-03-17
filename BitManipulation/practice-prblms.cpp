#include<iostream>
using namespace std;

void checkEvenOdd(int&n){
    if(n&1)
        cout << "Odd" << endl;
    else
        cout << "Even" << endl;
}

int main(){
    int n;
    cin >> n;
    checkEvenOdd(n);
    return 0;
}