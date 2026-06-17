class Solution {
public:
    
    // int solve(int i, vector<int>& cost, vector<int>& dp) {
    //     if(i >= cost.size()) {
    //         return 0;
    //     }

    //     if(dp[i] != -1) return dp[i];

    //     return dp[i] = cost[i] + min(solve(i+1, cost, dp), solve(i+2, cost, dp));
    // }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // vector<int>dp(n+1, -1);

        int next1 = 0;
        int next2 = 0;
        for(int i = n-1; i>=0; i--) {
            int curr = cost[i] + min(next1, next2);

            next2 = next1;
            next1 = curr;
        }

        return min(next1, next2);
    }
};