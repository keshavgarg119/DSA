class Solution {
public:
    // int solve(int n, vector<int>& dp) {
    //     if(n==0) return 0;

    //     if(dp[n]!=-1) return dp[n];

    //     int ans = INT_MAX;

    //     for(int i=1; i*i<=n; i++) {
    //         int square = i*i;

    //         ans = min(ans, 1+solve(n-square, dp));
    //     }

    //     return dp[n] = ans;
    // }
    int numSquares(int n) {

        vector<int>dp(n+1,INT_MAX);

        dp[0] = 0;

        for(int i=1; i<=n; i++) {
            for(int j=1; j*j<=i; j++) {
                int square = j*j;

                dp[i] = min(dp[i], 1+dp[i-square]);
            }
        }

        return dp[n];
        // Index:  0 1 2 3 4 5 6 7 8 9 10 11 12
        // DP   :  0 1 2 3 1 2 3 4 2 1  2  3  3
    }
};