#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int minCost(vector<int>&v){
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for(int i=0; i<v.size(); ++i){
        minHeap.push(v[i]);
    }

    int cost = 0;
    while(minHeap.size()>1){
        int f = minHeap.top();
        minHeap.pop();

        int s = minHeap.top();
        minHeap.pop();

        cost+=f+s;
        int sum=f+s;
        minHeap.push(sum);
    }
    return cost;
}

int main(){
    vector<int> v = {4,3,2,6};
    cout << minCost(v);
}