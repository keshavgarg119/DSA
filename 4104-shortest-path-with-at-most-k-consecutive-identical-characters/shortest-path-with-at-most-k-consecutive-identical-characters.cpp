class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> adj(n); // adj[u] = {v, w}
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        // dist[node][run], run in [1, k]
        vector<vector<long long>> dist(n, vector<long long>(k + 1, LLONG_MAX));
        priority_queue<tuple<long long,int,int>, 
                       vector<tuple<long long,int,int>>, 
                       greater<>> pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1}); // {weight, node, run}

        while (!pq.empty()) {
            auto [d, u, run] = pq.top(); pq.pop();
            if (d > dist[u][run]) continue; // stale entry

            if (u == n - 1) return (int)d; // first pop of n-1 = minimum (Dijkstra guarantee)

            for (auto& [v, w] : adj[u]) {
                int newRun = (labels[v] == labels[u]) ? run + 1 : 1;
                if (newRun > k) continue; // would violate the consecutive-char constraint

                long long nd = d + w;
                if (nd < dist[v][newRun]) {
                    dist[v][newRun] = nd;
                    pq.push({nd, v, newRun});
                }
            }
        }

        return -1;
    }
};