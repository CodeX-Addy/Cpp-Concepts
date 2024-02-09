#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

template<typename T>
class Graph{
    public:
    unordered_map<T, list<pair<T,int> > > adjList;
    
    void addEdge(T u, T v, int wt, bool isDir){
        if(isDir){
            adjList[u].push_back({v,wt});
        }
        else{
            adjList[u].push_back({v,wt});
            adjList[v].push_back({u,wt});
        }
    }

    // Breadth first search
    void bfsTraversal(T src, unordered_map<int,bool> vis){
        queue<int>q;
        q.push(src);
        vis[src] = true;
        while(!q.empty()){
            T frontNode = q.front();
            cout << frontNode << " ";
            q.pop();
            
            for(auto nbr : adjList[frontNode]){
                T nbrData = nbr.first;
                if(!vis[nbrData]){
                    q.push(nbrData);
                    vis[nbrData] = true;
                }
            }
        }
    }
    
};
int main(){
    Graph<char> g;
    g.addEdge('a','b',1,0);
    g.addEdge('a','c',5,0);
    g.addEdge('b','c',6,0);
    g.addEdge('c','d',18,0);
    g.addEdge('c','e',10,0);
    g.addEdge('e','f',11,0);
    
    
    unordered_map<int,bool> vis;
    for(char i='a';i<='f';++i){
        if(!vis[i]){
            cout << i << " ";
        }
    }
}
