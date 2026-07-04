class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>dist(n, 1e9);
        vector<vector<pair<int,int>>>adj(n);

        for(auto &it: flights) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
        }

        queue<pair<int, pair<int,int>>>q;
        // steps, source, dist
        q.push({0, {src,0}});
        dist[src] = 0;

        while(!q.empty()) {
            auto it = q.front();
            q.pop();

            int steps = it.first;
            int s = it.second.first;
            int d = it.second.second;
            if(steps > k) continue;

            for(auto iter: adj[s]) {
                int adjNode = iter.first;
                int adjW = iter.second;

                if(d + adjW < dist[adjNode] && steps <= k) {
                    dist[adjNode] = d + adjW;
                    q.push({steps+1, {adjNode, dist[adjNode]}});
                }
            }
        }

        if(dist[dst]==1e9) return -1;
        return dist[dst];
    }
};