#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool comp(int &a, int &b){
    return a<b;
}

void print(vector<int>&v){
    for (const auto &i : v)
    {
        cout << i << " ";
    }
}

void printvv(vector<vector<int>>&v){
   for(int i=0; i<v.size(); i++){
        vector<int>&temp = v[i];
        int a = temp[0];
        int b = temp[1];
        cout << a << " " << b << endl;
   } 
   cout << endl;
}

bool compvv(vector<int>&a, vector<int>&b){
    return a[1] < b[1];
}
int main(){
    //vector<int>v = {5,2,1,6,8,7};
    //sort(v.begin(), v.end()); -->by default inc order
    //sort(v.begin(), v.end(), comp); //comparator

    //For 2d vectors
    vector<vector<int>> v;
    int n = 5;
    for(int i=0; i<n; ++i){
        vector<int>temp;
        int a, b;
        cout << "Enter values:" << endl;
        cin >> a >> b;
        temp.push_back(a);
        temp.push_back(b);
        v.push_back(temp);
    }
    //sort(v.begin(), v.end()); --> by default by 0 index
    sort(v.begin(), v.end(), compvv); //sort by 1 index
    printvv(v);
}
