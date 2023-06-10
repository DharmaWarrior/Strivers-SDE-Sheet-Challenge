#include <bits/stdc++.h> 
void toposort(int node,vector<vector<int>> &graph, vector<int> &vis, stack<int> &st){
    vis[node] = 1;

    for(auto x: graph[node]){
        if(!vis[x]){
            toposort(x, graph, vis, st);
        }
    }
    st.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int n, int m)  {
    // Write your code here

    vector<vector<int>> graph(n, vector<int>());

    for (int i = 0; i < m; i++)
    {
        int u = edges[i][1];
        int v = edges[i][0];

        graph[v].push_back(u);
    }
    
    vector<int> vis(n,0);
    stack<int> st;

    for(int i=0;i<n;i++){
        if(!vis[i]){
            toposort(i,graph,vis,st);
        }
    }

    vector<int> ans;
    while(!st.empty()){
        int temp = st.top();
        st.pop();
        ans.push_back(temp);
    }
    return ans;
}


/*

#include <bits/stdc++.h> 

vector<int> topologicalSort(vector<vector<int>> &edges, int n, int m)  {
    // Write your code here

    vector<vector<int>> graph(n, vector<int>());

    for (int i = 0; i < m; i++)
    {
        int u = edges[i][1];
        int v = edges[i][0];

        graph[v].push_back(u);
    }
    
    int indegree[n] = {0};
		for (int i = 0; i < n; i++) {
			for (auto it : graph[i]) {
				indegree[it]++;
			}
		}

		queue<int> q;
		for (int i = 0; i < n; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}
		vector<int> topo;
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			topo.push_back(node);
			// node is in your topo sort
			// so please remove it from the indegree

			for (auto it : graph[node]) {
				indegree[it]--;
				if (indegree[it] == 0) q.push(it);
			}
		}

		return topo;
}

*/
