class Solution {
  public:
  
    int solve(int i, int j, vector<int>& a, vector<int>& b, vector<vector<int>>& dp) {
       
        int n = a.size();
        int m = b.size();
        
        if(j==m) return 0;
        if(i==n) return -1e9;
        
        if(n-i < m-j) return -1e9;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int match = a[i]*b[j] + solve(i+1, j+1, a, b, dp);
        
        int skip = solve(i+1, j, a, b, dp);
        
        return dp[i][j] = max(match, skip);
    }
    
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        // code here
        int n = a.size();
        int m = b.size();
        
        vector<vector<int>>dp(n, vector<int>(m,-1));
        
        return solve(0,0,a,b,dp);
    }
};
