// Inline function implementation
#include <iostream>
using namespace std;

inline int getMax(int a, int b){ // More efficient for using single line function body
    return (a>b)?a:b;
}
int main() {
    int a = 1;
    int b = 2;
    
    // Ternary operator
    int ans = getMax(a,b); // Replaces the function name with function body
    cout << ans << endl;
    int c=3,d=4;
    cout << getMax(c,d);// Replaces the function name with function body
    
    
    return 0;
}
