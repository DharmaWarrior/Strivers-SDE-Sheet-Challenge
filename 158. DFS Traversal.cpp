
#include<bits/stdc++.h>


void dfs(int node,int vis[], vector<int> adj[], vector<int> &temp){
    vis[node] = 1;
    temp.push_back(node);
    for(auto x : adj[node]){
        if(!vis[x]){
            dfs(x,vis,adj,temp);
        }
    }
}



vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<int> adj[V];
    int vis[V] = {0};

    for(int i =0;i<E;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> dfsans;
    for(int i=0;i<V;i++){
        if(!vis[i]){
            vector<int> temp;
            dfs(i,vis,adj,temp);
            dfsans.push_back(temp);
        }
    }

    return dfsans;
}
