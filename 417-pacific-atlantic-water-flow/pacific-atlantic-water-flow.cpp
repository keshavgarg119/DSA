class Solution {
public:
    void solve(int r, int c, vector<vector<int>>& heights, vector<vector<bool>>& vis) {
        int n = heights.size();
        int m = heights[0].size();

        vis[r][c] = true;

        int dr[4] = {-1,+1,0,0};
        int dc[4] = {0,0,-1,+1};
        for(int k=0; k<4; k++) {
            int nr = dr[k] + r;
            int nc = dc[k] + c;

            if(nr<0 || nr>=n || nc<0 || nc>=m) continue;

            if(vis[nr][nc]) continue;

            // reverse case-  must be 5->3->2 like this else skip the case
            if(heights[nr][nc] < heights[r][c]) continue;

            solve(nr, nc, heights, vis);
        }

    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<bool>>pacific(n, vector<bool>(m,false));
        vector<vector<bool>>atlantic(n, vector<bool>(m,false));

        for(int j=0; j<m; j++) {
            solve(0,j,heights, pacific);
        }

        for(int i=0; i<n; i++) {
            solve(i,0,heights,pacific);
        }

        for(int j=0; j<m; j++) {
            solve(n-1,j,heights,atlantic);
        }

        for(int i=0; i<n; i++) {
            solve(i,m-1,heights,atlantic);
        }

        vector<vector<int>>ans;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i,j});
                }
            }
        }

        return ans;
    }
};