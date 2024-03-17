#include<iostream>
#include<vector>
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

void getSubsequences(string str){
    vector<string> ans;
    int n = str.length();
    for(int i=0; i<(1<<n); ++i){
        string temp = "";
        for(int j=0; j<n; ++j){
            char ch = str[j];
            int mask = 1<<j;
            if(i & mask)
                temp.push_back(ch);
        }
        ans.push_back(temp);
    }
    for(auto i : ans)
        cout << i << " ";
}

int main(){
    int n;
    //cin >> n;
    //checkEvenOdd(n);
    //getithBit(4, 1);
    //setithBit(2,0);
    vector<int> v;
    getSubsequences("abc");
    
    return 0;
}