class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>dist(n, vector<int>(m,INT_MAX));

        pq.push({0,{0,0}});
        dist[0][0] = 0;

        int dr[4] = {+1,-1,0,0};
        int dc[4] = {0,0,-1,+1};

        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            
            int effort = curr.first;
            int r = curr.second.first;
            int c = curr.second.second;

            if(r==n-1 &&  c==m-1) return effort;

            if(effort > dist[r][c]) continue;

            for(int k=0; k<4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr>=0 && nr<n && nc>=0 && nc<m) {
                    int edgeCost = abs(heights[r][c] - heights[nr][nc]);
                    int newEffort = max(effort, edgeCost);

                    if(newEffort < dist[nr][nc]) {
                        dist[nr][nc] = newEffort;
                        pq.push({dist[nr][nc], {nr,nc}});
                    }
                }
            }
        }

        return 0;
    }
};