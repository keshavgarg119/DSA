class Solution {
public:
    int solve(int i, int m, vector<int>& suffix, vector<vector<int>>& dp) {
        int n = suffix.size();
        if(i>=n) return 0;

        if(2*m >= n-i) return suffix[i];

        if(dp[i][m]!=-1) return dp[i][m];

        int ans = 0;
        for(int x=1; x<=2*m; x++) {
            int opponent = solve(i+x, max(x,m), suffix, dp);

            ans = max(ans, suffix[i]-opponent);
        } 

        return dp[i][m] = ans;
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        vector<int>suffix(n);

        suffix[n-1] = piles[n-1];
        for(int i=n-2; i>=0; i--) {
            suffix[i] = suffix[i+1] + piles[i];
        }

        vector<vector<int>>dp(n, vector<int>(n+1,-1));

        return solve(0,1,suffix,dp);
    }
};