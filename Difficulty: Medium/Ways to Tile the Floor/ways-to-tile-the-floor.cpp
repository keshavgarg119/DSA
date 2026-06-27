class Solution {
  public:
    const int MOD = 1e9 + 7;
    
    int solve(int n, int m, vector<int>& dp) {
        if(n<m) return 1;
        
        if(n==m) return 2;
        
        if(dp[n]!=-1) return dp[n];
        
        return dp[n] = (solve(n-1,m,dp) + solve(n-m,m,dp)) % MOD;
    }
    
    int countWays(int n, int m) {
        // code here.
        vector<int>dp(n+1, -1);
        
        return solve(n,m,dp);
    }
};