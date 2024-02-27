#include<iostream>
#include<unordered_map>
#include<stack>
#include<list>
using namespace std;

class Graph{
    public:
    unordered_map<int,list<int>> adjList;

    void addEdge(int u, int v, bool isDirected){
        if(isDirected){
            adjList[u].push_back(v);
        }
        else{
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }

    void topoSortDfs(int src, unordered_map<int,bool> &visited, stack<int>& s){
        visited[src] = true;
        for(auto it : adjList[src]){
            if(!visited[it]){
                topoSortDfs(it, visited, s);
            }
        }

        s.push(src);
    }

    void printadjList(void){
        for(auto i : adjList){
            cout << i.first << ": {";
            for(auto j : i.second){
                cout << j << ", ";
            }
            cout << "}" << endl;
        }
    }
};


int main(){
    Graph g;
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 1);
    g.addEdge(3, 5, 1);
    g.addEdge(4, 6, 1);
    g.addEdge(6, 7, 1);

    //g.printadjList();
    stack<int> st;
    unordered_map<int,bool> visited;

    for(int node=0; node<8; ++node){
        if(!visited[node]){
            g.topoSortDfs(node, visited, st);
        }
    }

    //Printing values from the stack
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }

}