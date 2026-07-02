class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>dist(n, vector<int>(m,INT_MAX));
        deque<pair<int,int>>dq;

        dist[0][0] = grid[0][0];
        dq.push_front({0,0});

        int dr[4] = {-1,+1,0,0};
        int dc[4] = {0,0,-1,+1};

        while(!dq.empty()) {
            auto [r,c] = dq.front();
            dq.pop_front();

            for(int k=0; k<4; k++) {
                int nr = dr[k] + r;
                int nc = dc[k] + c;

                if(nr<0 || nr>=n || nc>=m || nc<0) continue;

                int w = grid[nr][nc];

                if(w+dist[r][c] < dist[nr][nc]) {
                    dist[nr][nc] = w + dist[r][c];

                    if(w==0) {
                        dq.push_front({nr,nc});
                    }
                    else {
                        dq.push_back({nr,nc});
                    }
                }
            }
        }

        return dist[n-1][m-1] < health;
    }
};

// | Edge Weights             | Algorithm   | Data Structure   |
// | ------------------------ | ----------- | ---------------- |
// | All equal (e.g., all 1)  | BFS         | `queue`          |
// | Only 0 and 1             | **0-1 BFS** | `deque`          |
// | Any non-negative weights | Dijkstra    | `priority_queue` |
