class Solution {
  public:
    
    int dp[10][82];
    
    int solve(int pos, int sum, int n) {
        if(sum < 0) return 0;
        
        if(pos == n) return sum==0;
        
        if(dp[pos][sum] != -1) return dp[pos][sum];
        
        int ans = 0;
        int start = (pos==0) ? 1 : 0;
        
        for(int i = start; i<=9; i++) {
            ans += solve(pos+1, sum-i, n);
        }
        
        return dp[pos][sum] = ans;
    }
    int countWays(int n, int sum) {
        // code here
        memset(dp, -1, sizeof(dp));

        int ans = solve(0, sum, n);

        return ans == 0 ? -1 : ans;
    }
};