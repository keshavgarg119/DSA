class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        int sum = 0;

        int start = 0, ansStart = 0, ansEnd = 0;
        for(int i=0; i<nums.size(); i++) {
            sum += nums[i];

            if(sum==0) {
                start = i;
            }

            if(sum > maxi) {
                maxi = sum;
                ansStart = start;
                ansEnd = i;
            }
            if(sum < 0) {
                sum = 0;
            }
        }

        return maxi;
    }
};