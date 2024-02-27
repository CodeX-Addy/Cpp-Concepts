//Using adjacency matrix
#include<iostream>
#include<vector>
#include<utility>
using namespace std;

//TC -- > O(n^2)  SC --> O(n^2)
class Graph{
    public:
    void createGraph(vector<pair<int, int> > edgeList){
        int n = edgeList.size();
        vector<vector<int> > adj(n, vector<int>(n,0));
        for(auto i : edgeList){
            int u = i.first;
            int v = i.second;
            adj[u][v] = 1;
        }
    }

    void printGraph(vector<vector<int>> adj){
        for(int i=0; i<adj.size(); ++i){
            for(int j=0; j<adj[i].size(); ++j){
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main(){
    vector<pair<int, int> > edgeList = {{0, 1}, {0, 2}, {1, 2}, {2, 3}, {3, 4}};
    Graph g;
    g.createGraph(edgeList);
    g.printGraph(); //Need to pass adjacency matrix to this function instead of creating a new one
    return 0;
}

