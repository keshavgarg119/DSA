class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        vector<int> mavontelia = nums; 

        int n = nums.size();

        int ans = INT_MIN;
        int maxLeft = nums[0];

        for (int j = k; j < n; j++) {
            maxLeft = max(maxLeft, nums[j - k]);
            ans = max(ans, maxLeft + nums[j]);
        }

        return ans;
    }
};