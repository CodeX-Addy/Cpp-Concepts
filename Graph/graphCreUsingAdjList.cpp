#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

template<typename T>
class Graph{
    public:
    unordered_map<T, list<pair<T,int>>> adjList;

    //creating function for adding an edge
    void addEdge(T u, T v, int w, bool flag){
        if(flag) adjList[u].push_back({v,w});
        else{
            adjList[u].push_back({v, w});
            adjList[v].push_back({u, w});
        }
    }

    void print(){
        for(auto i : adjList){
            cout << i.first << "->";
            for(pair<T,int> j : i.second){
                cout << j.first << "," << j.second;
            }
            cout << endl;
        }
    }
};
int main(){
    Graph<int> g;
    g.addEdge(1,2,3,1);
    g.addEdge(2,3,5,1);
    g.addEdge(2,4,6,1);
    g.addEdge(4,8,1,1);

    g.print();
}