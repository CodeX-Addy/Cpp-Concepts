// Dynamic memory allocation
// From the given program we can return the sum of all the elements of a dynamic array
#include <iostream>
using namespace std;

int getSum(int *arr, int n){
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n]; // This is how we're creating the dynamic/variable size array
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    int ans = getSum(arr, n);
    cout << "The sum is " << ans << endl;

    return 0;
}
