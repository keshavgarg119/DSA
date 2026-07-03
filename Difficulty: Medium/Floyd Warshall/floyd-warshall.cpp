class Solution {
public:
    void floydWarshall(vector<vector<int>> &dist) {

        int V = dist.size();
        const int INF = 100000000;

        // Distance from a node to itself is always 0
        for (int i = 0; i < V; i++) {
            dist[i][i] = 0;
        }

        // Floyd-Warshall
        for (int via = 0; via < V; via++) {

            for (int i = 0; i < V; i++) {

                if (dist[i][via] == INF) continue;

                for (int j = 0; j < V; j++) {

                    if (dist[via][j] == INF) continue;

                    dist[i][j] = min(dist[i][j],
                                     dist[i][via] + dist[via][j]);
                }
            }
        }
    }
};