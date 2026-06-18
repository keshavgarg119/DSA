class Solution {
public:
    // int solve(int index, int prev, vector<int>& nums, vector<vector<int>>& dp) {
    //     if(index==nums.size()) {
    //         return 0;
    //     }

    //     if(dp[index][prev+1]!=-1) return dp[index][prev+1];

    //     int length = solve(index+1, prev, nums, dp);
    //     if(prev==-1 || nums[index] > nums[prev]) {
    //         length = max(length, 1 + solve(index+1, index, nums, dp));
    //     }

    //     return dp[index][prev+1] = length;
    // }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>>dp(n+1, vector<int>(n+1,0));

        for(int i=n-1; i>=0; i--) {
            for(int prev=i-1; prev>=-1; prev--) {
                int length = dp[i+1][prev+1];
                if(prev==-1 || nums[i] > nums[prev]) {
                    length = max(length, 1 + dp[i+1][i+1]);
                }
                dp[i][prev+1] = length;
            }
        }

        return dp[0][0];
    }
};