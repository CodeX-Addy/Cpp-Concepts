#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<limits.h>
#include<stack>
using namespace std;

class Graph{
    public:
    unordered_map<int, list<pair<int,int>>> adjList;

    void addEdge(int u, int v, int wt, bool isDirected){
        if(isDirected){
            adjList[u].push_back({v,wt});
        }
        else{
            adjList[u].push_back({v,wt});
            adjList[v].push_back({u,wt});

        }
    }

    void topoSortDfs(int src, stack<int>&topoOrder, unordered_map<int,bool>&vis){
        vis[src] = true;
        for(auto nbr : adjList[src]){
            int nbrNode = nbr.first;
            if(!vis[nbrNode]){
                vis[nbrNode] = true;
                topoSortDfs(nbrNode, topoOrder, vis);
            }
        }

        topoOrder.push(src);
    }

    void shortestPathDfs(stack<int>&topoOrder, int n){
        vector<int>dist(n, INT_MAX);

        int src = topoOrder.top();
        topoOrder.pop();
        dist[src] = 0;

        for(auto nbr : adjList[src]){
            int nbrNode = nbr.first;
            int nbrDist = nbr.second;

            if(dist[src] + nbrDist < dist[nbrNode]){
                dist[nbrNode] = dist[src] + nbrDist;
            }
        }

        while(!topoOrder.empty()){
            int src = topoOrder.top();
            topoOrder.pop();
            for(auto nbr : adjList[src]){
                int nbrNode = nbr.first;
                int nbrDist = nbr.second;

                if(dist[src] + nbrDist < dist[nbrNode]){
                    dist[nbrNode] = dist[src] + nbrDist;
            }
        }
        }
        
        cout << "Printing distance array:" << endl;
        for(auto i : dist){
            cout << i << " ";
        }
    }

    void print(){
        for(auto i : adjList){
            cout << i.first << ": {";
            for(auto j : i.second){
                cout << "(" << j.first << "," << j.second << ") ";
            }
            cout << "}" << endl;
        }
    }
};

int main(){
    Graph g;
    g.addEdge(0, 1, 5, true);
    g.addEdge(0, 2, 3, true);
    g.addEdge(1, 3, 3, true);
    g.addEdge(2, 1, 2, true);
    g.addEdge(2, 3, 5, true);
    g.addEdge(2, 4, 6, true);
    g.addEdge(4, 3, 1, true);

    //g.print();
    unordered_map<int, bool> vis;
    stack<int> topoOrder;
    g.topoSortDfs(0, topoOrder, vis);
    /*while(!topoOrder.empty()){
        cout << topoOrder.top() << " ";
        topoOrder.pop();
    }*/
    

    //cout << endl;
    g.shortestPathDfs(topoOrder, 5);
    

    return 0;
}