class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int maxProduct = INT_MIN;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int s1 = nums[0];
        int s2 = nums[1];
        int l1 = nums[n-1];
        int l2 = nums[n-2];
        int l3 = nums[n-3];

        return max(s1*s2*l1, l1*l2*l3);
    }
};