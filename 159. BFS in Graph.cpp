#include <bits/stdc++.h> 
vector<int> BFS(int V, vector<pair<int, int>> edges)
{
    // Write your code here
    vector<set<int>> adj(V);
    int vis[V] = {0};

    for(auto e:edges){
        int u = e.first;
        int v = e.second;

        adj[u].insert(v);
        adj[v].insert(u);
    }
    vector<int> ans;
    for(int i=0;i<V;i++){
        if(!vis[i]){
            queue<int> q;
            q.push(i);

            while(!q.empty()){
                int node = q.front();
                q.pop();
                
                ans.push_back(node);
                vis[node]=1;
                for(auto x: adj[node]){
                    if(!vis[x]){
                        vis[x]=1;
                        q.push(x);
                    }
                }
    }
        }
    }
    
    
    return ans;
}
