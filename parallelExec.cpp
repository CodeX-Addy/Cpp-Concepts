//Parallel execution is used to do the given task concurrently and try to use multicore 
#include<iostream>
#include<algorithm>
#include<vector>
#include<execution>
using namespace std;

int main(){
    vector<int> v = {2,1,8,5,3,4,6,9};

    sort(execution::par,v.begin(), v.end());

    for(auto&i : v){
        cout << i << " ";
    }
}