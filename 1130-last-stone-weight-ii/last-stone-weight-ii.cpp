class Solution {
public:
    // bool solve(int i, int target, vector<vector<int>>& dp, vector<int>& stones) {
    //     if(target==0) return true;

    //     if(i==0) return stones[0]==target;

    //     if(dp[i][target]!=-1) return dp[i][target];

    //     bool notTake = solve(i-1, target, dp, stones);
    //     bool take = false;

    //     if(target >= stones[i]) {
    //         take = solve(i-1, target-stones[i], dp, stones);
    //     }

    //     return dp[i][target] = take || notTake;
    // }

    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int total = accumulate(stones.begin(), stones.end(), 0);

        // vector<vector<int>>dp(n, vector<int>(total+1, -1));
        vector<vector<bool>>dp(n, vector<bool>(total+1, false));

        for(int i=0; i<n; i++) {
            dp[i][0] = true;
        }
        if(stones[0] <= total) {
            dp[0][stones[0]] = true;
        }

        for(int i=1; i<n; i++) {
            for(int t=1; t<=total; t++) {
                bool notTake = dp[i-1][t];

                bool take = false;
                if(stones[i] <= t) {
                    take = dp[i-1][t-stones[i]];
                }

                dp[i][t] = take || notTake;
            }
        }

        int ans = INT_MAX;
        for(int sum = total/2; sum>=0; sum--) {
            if(dp[n-1][sum]) {
                // return total - 2*sum; // divide the stones array in two subsets and checking whether the subset with given sum is possible or not
                ans = min(ans, total-2*sum);
            }
        }

        return ans;
    }
};