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
        vector<int>dp(n+1,0);

        // if(n==1) return 1;
        dp[1] = 1;

        for(int i=2; i<=n; i++) {
            for(int j=1; j<i; j++) {
                dp[i] = max(dp[i], max(j*(i-j), j*dp[i-j]));
            }
        }

        return dp[n];
    }
};




// key idea

// 1|9      max(1*9, 1*dp[9])

// 2|8      max(2*8, 2*dp[8])

// 3|7      max(3*7, 3*dp[7])

// 4|6      max(4*6, 4*dp[6])

// 5|5      max(5*5, 5*dp[5])

// 6|4      max(6*4, 6*dp[4])

// 7|3      max(7*3, 7*dp[3])

// 8|2      max(8*2, 8*dp[2])

// 9|1      max(9*1, 9*dp[1])