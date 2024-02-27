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

    bool isCyclePresentUsingBfs(T src, unordered_map<T, bool> &vis){
        queue<int>q;
        q.push(src);
        vis[src] = true;
        while(!q.empty()){
            T frontNode = q.front();
            q.pop();

            for(auto nbr : adjList[frontNode]){
                T nbrData = nbr.first;
                if(!vis[nbrData]){
                    q.push(nbrData);
                    vis[nbrData] = true;
                }
                else{   
                    return true;
                }
            }
        }
        return false;
    }
    

    void dfsTraversal(T src, unordered_map<char,bool>&vis){
        vis[src] = true;
        cout << src << " ";

        for(auto nbr : adjList[src]){
            T nbrData = nbr.first;
            if(!vis[nbrData]){
                dfsTraversal(nbrData,vis);
            }
        }
    }

    void noOfDisconnectedComp(T src, unordered_map<char, bool>&vis){
        int count = 0;
        for(auto i : adjList){
            T node = i.first;
            if(!vis[node]){
                dfsTraversal(node, vis);
                count++;
            }
        }
        cout << count;
    }
    
};
int main(){
    Graph<char> g;
    g.addEdge('a','b',1,1);
    g.addEdge('b','c',6,1);
    g.addEdge('c','d',18,1);
    g.addEdge('c','e',10,1);
    g.addEdge('d','e',23,1);
    g.addEdge('e','f',11,1);
    
    
    unordered_map <T,bool> vis;
    //for(char i='a';i<='f';++i){
      //  if(!vis[i]){
        //    g.bfsTraversal(i, vis);
        //}
    //}
    /*for(char i='a';i<='f';++i){
        if(!vis[i]){
            g.dfsTraversal( i , vis );
        }
    }*/

    bool isCyclePresent = g.isCyclePresentUsingBfs('a', vis);
    if(isCyclePresent){
        cout << "Cycle Present";
    }else{
        cout << "No Cycle Found";
    }
    return 0;
    
    
}