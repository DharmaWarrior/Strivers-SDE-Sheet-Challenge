#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int V, int edges, int S) {
    unordered_map<int, list<pair<int,int> > > adj;

    for(int i=0;i<edges;i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int wt = vec[i][2];

        adj[u].push_back(make_pair(v,wt));
        adj[v].push_back(make_pair(u,wt));
    }
    // Create a set ds for storing the nodes as a pair {dist,node}
        // where dist is the distance from source to the node.
        // set stores the nodes in ascending order of the distances 
        set<pair<int,int>> st; 

        // Initialising dist list with a large number to
        // indicate the nodes are unvisited initially.
        // This list contains distance from source to the nodes.
        vector<int> dist(V, INT_MAX); 
        
        st.insert({0, S}); 

        // Source initialised with dist=0
        dist[S] = 0;
        
        // Now, erase the minimum distance node first from the set
        // and traverse for all its adjacent nodes.
        while(!st.empty()) {
            auto it = *(st.begin()); 
            int node = it.second; 
            int dis = it.first; 
            st.erase(it); 
            
            // Check for all adjacent nodes of the erased
            // element whether the prev dist is larger than current or not.
            for(auto it : adj[node]) {
                int adjNode = it.first; 
                int edgW = it.second; 
                
                if(dis + edgW < dist[adjNode]) {
                    // erase if it was visited previously at 
                    // a greater cost.
                    if(dist[adjNode] != 1e9) 
                        st.erase({dist[adjNode], adjNode}); 
                        
                    // If current distance is smaller,
                    // push it into the queue
                    dist[adjNode] = dis + edgW; 
                    st.insert({dist[adjNode], adjNode}); 
                 }
            }
        }
        // Return the list containing shortest distances
        // from source to all the nodes.
        return dist; 
}

/*
// priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        // vector<int> dist(V);
        // for(int i=0;i<V;i++){
        //     dist[i] = 1e9;
        // }
        // dist[S] = 0;
        // pq.push({0,S});
        
        // while(!pq.empty()){
        //     int dis = pq.top().first;
        //     int node = pq.top().second;
        //     pq.pop();
            
        //     for(auto it: adj[node]){
        //         int edgeweight = it[1];
        //         int adjnode = it[0];
                
        //         if(dis + edgeweight < dist[adjnode]){
        //             dist[adjnode] = dis + edgeweight;
        //             pq.push({dist[adjnode],adjnode});
        //         }
        //     }
        // }
        // return dist;
       
*/
