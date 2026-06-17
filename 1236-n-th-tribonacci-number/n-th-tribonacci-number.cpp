class Solution {
public:
    // int solve(int n, vector<int>& dp) {
    //     if(n==0) return 0;
    //     if(n==1 || n==2) return 1;

    //     if(dp[n]!=-1) return dp[n];
        
    //     return dp[n] = solve(n-1,dp) + solve(n-2, dp) + solve(n-3, dp);
    // }
    int tribonacci(int n) {

        //vector<int>dp(n+1, 0);

        if(n==0) return 0;
        if(n==1 || n==2) return 1;

        int prev3 = 0;
        int prev1 = 1;
        int prev2 = 1;

        for(int i=3; i<=n; i++) {
            int curr = prev1 + prev2 + prev3;
            prev3 = prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};