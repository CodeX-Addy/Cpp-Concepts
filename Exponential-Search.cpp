#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int>&arr, int s, int e, int k){
    while(s<=e){
        int mid = s + (e-s)/2;
        if(arr[mid] == k)
            return mid;
        else if(k>arr[mid])
            s = mid + 1;
        else
            e = mid - 1;
    }
    return -1;
}

int expSearch(vector<int>&arr, int k){
    int n = arr.size();
    if(arr[0] == k) return 0;
    int i=1;
    while(i<arr.size() && arr[i]<k){
        i *= 2;
    }
    return binarySearch(arr, i/2, min(i, n-1) , k);
}

int main(){
    vector<int>arr = {4,5,6,7,8,9,10};
    int ans = expSearch(arr, 4);
    cout << ans << endl;
}

//More about exp search
// https://en.wikipedia.org/wiki/Exponential_search
