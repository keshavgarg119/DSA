class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<int>vis(V, false);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        vector<vector<pair<int,int>>>adj(V);
        
        for(auto &it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        pq.push({0,0});
        
        int sum = 0;
        
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            
            int node = it.second;
            int wt = it.first;
            
            if(vis[node]) continue;
            sum += wt;
            vis[node] = true;
            
            for(auto &i: adj[node]) {
                int adjNode = i.first;
                int adjW = i.second;
                
                if(!vis[adjNode]) {
                    pq.push({adjW, adjNode});
                }
            }
        }
        
        return sum;
    }
};