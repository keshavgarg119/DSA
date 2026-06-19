class Solution {
public:
    int solve(int n, vector<int>& dp) {
        if(n==1) return 1;

        if(dp[n]!=-1) return dp[n];

        int ans = 0;
        for(int j=1; j<n; j++) {
            ans = max(ans, max(j*(n-j), j*solve(n-j,dp)));
        }

        return dp[n] = ans;
    }
    int integerBreak(int n) {
        vector<int>dp(n+1,-1);

        return solve(n,dp);
    }
};