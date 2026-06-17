class Solution {
public:
    // int solve(int n, vector<int>& dp) {
    //     if(n<=2) return n;

    //     if(dp[n]!=-1) return dp[n];

    //     return dp[n] = solve(n-1, dp) + solve(n-2, dp);
    // }
    int climbStairs(int n) {
        if(n<=2) return n;

        int prev2 = 1;
        int prev1 = 2;
        
        for(int i=3; i<=n; i++) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};