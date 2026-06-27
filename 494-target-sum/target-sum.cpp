class Solution {
public:
    // int solve(int i, int sum, vector<int>& nums, vector<vector<int>>& dp) {
    //     if(i==0) {
    //         if(sum==0 && nums[0]==0) return 2;

    //         if(sum==0 || sum==nums[0]) {
    //             return 1;
    //         }

    //         return 0;
    //     }

    //     if(dp[i][sum]!=-1) return dp[i][sum];

    //     int notTake = solve(i-1, sum, nums, dp);

    //     int take = 0;
    //     if(nums[i] <= sum) {
    //         take = solve(i-1, sum-nums[i], nums, dp);
    //     }

    //     return dp[i][sum] = take + notTake;
    // }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);

        if(abs(target) > total) return 0;
        if((total+target)%2) return 0;

        int req = (total+target)/2;

        vector<vector<int>>dp(n, vector<int>(req+1,0));

        if (nums[0] == 0)
            dp[0][0] = 2;
        else
            dp[0][0] = 1;

        if (nums[0] != 0 && nums[0] <= req)
            dp[0][nums[0]] = 1;

        for (int i = 1; i < n; i++) {
            for (int sum = 0; sum <= req; sum++) {

                int notTake = dp[i - 1][sum];

                int take = 0;
                if (nums[i] <= sum)
                    take = dp[i - 1][sum - nums[i]];

                dp[i][sum] = take + notTake;
            }
        }

        return dp[n - 1][req];
    }
};