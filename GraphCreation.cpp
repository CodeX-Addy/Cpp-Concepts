
#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class Graph{
    public:
    unordered_map<int,list<int>> adjList;

    //adding edge
    void addEdge(int u, int v, bool flag){
        //assuming directed when flag is 1
        if(flag){
            adjList[u].push_back(v);
        }
        else{
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }

    //printing graph as per edges
    void print(){
        for(auto i : adjList){
            cout << i.first << "-> {";
            for(auto j : i.second){
                cout << j << ",";
            } 
            cout << "}";
            cout << endl;
        }
    }
};

int main(){
    Graph g;
    g.addEdge(1,2,1);
    g.addEdge(4, 1, 1);

    g.print();
}
