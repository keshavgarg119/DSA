class Solution {
public:
    // int solve(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& grid) {
    //     if(i==0 && j==0) return grid[0][0];
    //     if(i<0 || j<0) return 1e9;

    //     if(dp[i][j]!=-1) return dp[i][j];
        
    //     int up = solve(i-1,j,dp,grid);
    //     int left = solve(i,j-1,dp,grid);

    //     return dp[i][j] = grid[i][j] + min(up, left);
    // }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // vector<vector<int>>dp(m, vector<int>(n,0));
        vector<int>prev(n,0);

        for(int i=0; i<m; i++) {
            vector<int>curr(n,0);

            for(int j=0; j<n; j++) {
                if(i==0 && j==0){
                    curr[j] = grid[0][0];
                    continue;
                }

                int up = 1e9, left = 1e9;
                
                if(i>0) up = prev[j];
                if(j>0) left = curr[j-1];

                curr[j] = grid[i][j] + min(up, left);
            }
            prev = curr;
        }

        return prev[n-1];
    }
};