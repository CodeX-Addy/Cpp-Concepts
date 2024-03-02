#include<iostream>
#include<unordered_map>
#include<stack>
#include<map>
#include<list>
#include<queue>
#include<algorithm>
#include<vector>
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


   //KAHN'S ALGO
   void topoSortBfs(int n,vector<int> &topoOrder){
    queue<int> q;
    unordered_map<int,int> indegree;
    

    for(auto i : adjList){
        for(auto j : i.second){
            ++indegree[j];
        }
    }
    
    //The case of 0th node will be covered here
    for(int node = 0; node < n; ++node){
        if(!indegree[node]) q.push(node);
    }

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        topoOrder.push_back(frontNode);

        for(auto i : adjList[frontNode]){
            --indegree[i];

            if(!indegree[i]) q.push(i);
        }
    }
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
    g.addEdge(0, 5, 0);
	g.addEdge(5, 4, 0);
	g.addEdge(4, 3, 0);
	g.addEdge(0, 6, 0);
	g.addEdge(6, 3, 0);
	g.addEdge(0, 1, 0);
	g.addEdge(1, 2, 0);
	g.addEdge(2, 3, 0);

    //g.printadjList();
    /*stack<int> st;
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
    }*/
    
    vector<int> topoOrder;

    g.topoSortBfs(8,topoOrder);

    for(auto i : topoOrder){
        cout << i << " "; 
    }
    
    //Detecting cycle in directed graph using bfs topo sort
    if(topoOrder.size() == n) cout << "No cycle present" << endl;
    else cout << "Cycle present" << endl;
  
    return 0;

}