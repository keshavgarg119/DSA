class Solution {
  public:
    const int MOD = 1e9+7;
    
    int solve(int pos, int count, int last, int n, int k, vector<vector<vector<int>>>&dp) {
        
        if(count>k) return 0;
        if(pos == n) return count==k;
        
        if(dp[pos][count][last]!=-1) return dp[pos][count][last];
        
        long long ans = 0;
        
        ans += solve(pos+1, count, 0, n, k, dp);
        
        if(last == 1) {
            ans += solve(pos+1, count+1, 1, n, k, dp);
        }
        else {
            ans += solve(pos+1, count, 1, n, k, dp);
        }
        
        return dp[pos][count][last] = ans%MOD;
    }
    int countStrings(int n, int k) {
        // code here
        if(n==1) return (k==0) ? 2 : 0;
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(k+2, vector<int>(2,-1)));
        
        long long ans = 0;
        
        ans += solve(1,0,0,n,k,dp);
        ans += solve(1,0,1,n,k,dp);
        
        return ans % MOD;
    }
};