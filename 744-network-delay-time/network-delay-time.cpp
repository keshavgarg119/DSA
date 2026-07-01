class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int src = k;
        vector<int>dist(n+1,INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;

        pq.push({0,src});
        dist[src] = 0;

        vector<vector<pair<int,int>>>adj(n+1);
        for(auto &t: times) {
            int u = t[0];
            int v = t[1];
            int wt = t[2];

            adj[u].push_back({v,wt});
        }

        while(!pq.empty()) {
            auto [d,node] = pq.top();
            pq.pop();

            if(d>dist[node]) continue;

            for(auto &[adjNode, wt]: adj[node]) {
                if(dist[node] + wt < dist[adjNode]) {
                    dist[adjNode] = dist[node] + wt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        int maxi = 0;
        for(int i=1; i<=n; i++) {
            if(dist[i]==INT_MAX) {
                return -1;
            }
            maxi = max(maxi, dist[i]);
        }
        return maxi;
    }
};