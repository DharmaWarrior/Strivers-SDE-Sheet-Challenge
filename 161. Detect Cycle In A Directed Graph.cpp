#include <bits/stdc++.h>


int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
    vector<int> graph[n+1];

    int indegree[n+1] = {0};
    
    for (auto e:edges)
    {
        int u = e.first;
        int v = e.second;

        graph[u].push_back(v);
        indegree[v]++;
    }

		queue<int> q;
		
    for (int i = 1; i <= n; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}

		int cnt = 0;
		
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			cnt++;
			// node is in your topo sort
			// so please remove it from the indegree

			for (auto it : graph[node]) {
				indegree[it]--;
				if (indegree[it] == 0) q.push(it);
			}
		}

		if (cnt == n) return false;
		return true;
}
