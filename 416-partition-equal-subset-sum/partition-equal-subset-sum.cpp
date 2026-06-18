class Solution {
public:
    bool solve(int index, int target, vector<vector<int>>& dp, vector<int>& nums) {
        if(target==0) return true;

        if(index==nums.size() || target<0) return false;

        if(dp[index][target]!=-1) return dp[index][target];

        bool take = solve(index+1, target-nums[index], dp, nums);
        bool notTake = solve(index+1, target, dp, nums);

        return dp[index][target] = take || notTake;

    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();

        sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2!=0) return false;
        int k = sum/2;

        vector<vector<int>>dp(n+1, vector<int>(k+1,-1));

        return solve(0,k,dp,nums);
    }
};