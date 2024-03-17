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

void setithBit(int n, int i){
    int mask = 1<<i;
    n = n | mask;
    cout << "Updated number: " << n << endl;
}

void clearithBit(int n, int i){
    int mask = ~(1<<i);
    n=n&mask;
}

bool fastCheckPowerOf2(int n) {
	if((n & (n-1)) == 0)
		return true;
	else 
		return false;
}

int fastCOuntSetBits(int n) {
	int count = 0;
	while(n != 0) {
		//cout << "n value: " << n << endl;
		count++;
		n = (n & (n-1));
	}
	return count;
}

int main(){
    int n;
    //cin >> n;
    //checkEvenOdd(n);
    //getithBit(4, 1);
    setithBit(2,0);
    return 0;
}