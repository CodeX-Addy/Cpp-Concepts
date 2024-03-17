#include<iostream>
using namespace std;

void checkEvenOdd(int&n){
    if(n&1)
        cout << "Odd" << endl;
    else
        cout << "Even" << endl;
}

void getithBit(int n, int i){
    int mask = 1<<i;
    int ans = n&mask;
    if(ans)
        cout << "Bit is->1" << endl;
    else
        cout << "Bit is->0" << endl;
}

int main(){
    int n;
    //cin >> n;
    //checkEvenOdd(n);
    getithBit(4, 1);
    return 0;
}