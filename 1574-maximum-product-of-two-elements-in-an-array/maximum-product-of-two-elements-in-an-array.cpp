class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // sort(nums.rbegin(), nums.rend());

        // return (nums[0]-1)*(nums[1]-1);
        int n = nums.size();
        int maxi1 = INT_MIN;
        int maxi2 = INT_MIN;

        for(int i=0; i<n; i++) {
            if(nums[i] > maxi1) {
                maxi2 = maxi1;
                maxi1 = nums[i];
            }
            else if(nums[i] > maxi2) {
                maxi2 = nums[i];
            }
        }

        return (maxi1-1)*(maxi2-1);
    }
};