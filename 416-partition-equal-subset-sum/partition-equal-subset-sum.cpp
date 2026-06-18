class Solution {
public:
    // bool solve(int index, int target, vector<vector<int>>& dp, vector<int>& nums) {
    //     if(target==0) return true;

    //     if(index==nums.size() || target<0) return false;

    //     if(dp[index][target]!=-1) return dp[index][target];

    //     bool take = solve(index+1, target-nums[index], dp, nums);
    //     bool notTake = solve(index+1, target, dp, nums);

    //     return dp[index][target] = take || notTake;

    // }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();

        sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2!=0) return false;
        int k = sum/2;

        vector<vector<bool>>dp(n+1, vector<bool>(k+1,false));

        // for this code we write if(target==0) return true;
        for(int i=0; i<=n; i++) {
            dp[i][0] = true;
        }

        for(int index=1; index<=n; index++) {
            for(int target=1; target<=k; target++) {
                bool take = false;
                bool notTake = dp[index-1][target];

                if(target >= nums[index-1]) {
                    take = dp[index-1][target-nums[index-1]];
                }

                dp[index][target] = take || notTake;
            }   
        }

        return dp[n][k];
    }
};