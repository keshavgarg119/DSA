class Solution {
  public:
  
    // int solve(int i, int j, vector<int>& a, vector<int>& b, vector<vector<int>>& dp) {
       
    //     int n = a.size();
    //     int m = b.size();
        
    //     if(j==m) return 0;
    //     if(i==n) return -1e9;
        
    //     if(n-i < m-j) return -1e9;
        
    //     if(dp[i][j]!=-1) return dp[i][j];
        
    //     int match = a[i]*b[j] + solve(i+1, j+1, a, b, dp);
        
    //     int skip = solve(i+1, j, a, b, dp);
        
    //     return dp[i][j] = max(match, skip);
    // }
    
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        // code here
        int n = a.size();
        int m = b.size();
        
        
        // vector<vector<int>>dp(n+1, vector<int>(m+1,-1e9));
        vector<int>curr(m+1, -1e9), next(m+1, -1e9);
        
        curr[m] = 0;
        next[m] = 0;
        
        for(int i=n-1; i>=0; i--) {
            for(int j=m-1; j>=0; j--) {
                
                if(n-i < m-j) {
                    curr[j] = -1e9;
                    continue;
                }
                
                int match = a[i]*b[j] + next[j+1];
                int skip = next[j];
                
                curr[j] = max(match, skip);
            }
            next = curr;
        }
        return next[0];
    }
};
