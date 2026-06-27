class Solution {
  public:
    const int MOD = 1e9 + 7;
    
    // int solve(int n, int m, vector<int>& dp) {
    //     if(n<m) return 1;
        
    //     if(n==m) return 2;
        
    //     if(dp[n]!=-1) return dp[n];
        
    //     return dp[n] = (solve(n-1,m,dp) + solve(n-m,m,dp)) % MOD;
    // }
    
    int countWays(int n, int m) {
        // code here.
        vector<int>dp(n+1, 0);
        
        dp[0] = 1;
        for(int i=1; i<=n; i++) {
            if(i<m) {
                dp[i] = 1;
            }
            else if(i==m){ 
                dp[i] = 2;
            }
            else {
                dp[i] = (dp[i-1] + dp[i-m]) % MOD;
            }
        }
        return dp[n];
    }
};