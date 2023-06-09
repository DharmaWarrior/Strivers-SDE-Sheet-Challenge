
#include<bits/stdc++.h>

bool isCycle (int vertex, vector<vector<int>>& graph, vector<bool>& visited, int parent)
{
    visited[vertex] = true;

    for (int adjVertex : graph[vertex])
    {
        if (visited[adjVertex] == false)
        {
            if (isCycle (adjVertex, graph, visited, vertex) == true)
            {
                return true;
            }
        }
        else if (adjVertex != parent)
        {
            return true;
        }
    }

    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<vector<int>> graph(n + 1, vector<int>());

    for (int i = 0; i < m; i++)
    {
        int u = edges[i][1];
        int v = edges[i][0];

        graph[v].push_back(u);
        graph[u].push_back(v);
    }

    vector<bool> visited(n + 1, false);

    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == false)
        {
            if (isCycle (i, graph, visited, -1) == true)
            {
                return "Yes";
            }
        }
    }

    return "No";
}


/*
bool detectbfs(int src, vector<int> adj[], int vis[]) {
      vis[src] = 1; 
      // store <source node, parent node>
      queue<pair<int,int>> q; 
      q.push({src, -1}); 
      // traverse until queue is not empty
      while(!q.empty()) {
          int node = q.front().first; 
          int parent = q.front().second; 
          q.pop(); 
          
          // go to all adjacent nodes
          for(auto adjacentNode: adj[node]) {
              // if adjacent node is unvisited
              if(!vis[adjacentNode]) {
                  vis[adjacentNode] = 1; 
                  q.push({adjacentNode, node}); 
              }
              // if adjacent node is visited and is not it's own parent node
              else if(parent != adjacentNode) {
                  // yes it is a cycle
                  return true; 
              }
          }
          return false; 
      }
*/
