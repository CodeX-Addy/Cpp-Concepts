#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<limits.h>
#include<set>
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

    void dijkstraAlgo(int n, int src, int dest){
        vector<int>dist(n+1, INT_MAX);
        set<pair<int,int>> st;

        st.insert({0,src});
        dist[src] = 0;

        while(!st.empty()){
            auto topElement = st.begin();
            pair<int,int>topPair = *topElement;
            int topDist = topPair.first;
            int topNode = topPair.second;

            st.erase(st.begin());

            for(pair<int,int> nbr : adjList[topNode]){
                int nbrNode = nbr.first;
                int nbrDist = nbr.second;

                if(topDist + nbrDist < dist[nbrNode]){

                    auto prevEntry = st.find({dist[nbrNode], nbrNode});
                    if(prevEntry!=st.end()){
                        st.erase(prevEntry);
                    }

                    dist[nbrNode] = topDist + nbrDist;
                    st.insert({dist[nbrNode], nbrNode});
                }
            }
        }
        if (dist[dest] == INT_MAX) 
               cout << "There is no path from Node " << src << " to Node " << dest << endl;
        else 
               cout << "Shortest Distance from Node " << src << " to Node " << dest << ": " << dist[dest] << endl;


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
	g.addEdge(1,6,14,0);
	g.addEdge(1,3,9,0);
	g.addEdge(1,2,7,0);
	g.addEdge(2,3,10,0);
	g.addEdge(2,4,15,0);
	g.addEdge(3,4,11,0);
	g.addEdge(6,3,2,0);
	g.addEdge(6,5,9,0);
	g.addEdge(5,4,6,0);

    //g.print();
    unordered_map<int, bool> vis;
    stack<int> topoOrder;
    g.topoSortDfs(0, topoOrder, vis);
    /*while(!topoOrder.empty()){
        cout << topoOrder.top() << " ";
        topoOrder.pop();
    }*/
    

    //cout << endl;
    //g.shortestPathDfs(topoOrder, 5);
    int n = 6;
	int src = 6;
	int dest = 4;
	g.dijkstraAlgo(n, src, dest);
    

    return 0;
}