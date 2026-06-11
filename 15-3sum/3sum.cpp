class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>>result;

        int n = nums.size();

        for(int i=0; i<n; i++) {

            if(i > 0 && nums[i] == nums[i-1]) continue;

            int left = i+1;
            int right = n-1;
            int target = -nums[i];

            while(left<right) {

                int sum = nums[left] + nums[right];
                if(target>sum) {
                    left++;
                }
                else if(target<sum) {
                    right--;
                }
                else {
                    result.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    
                    // Skip duplicate left
                    while(left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }

                    // Skip duplicate right
                    while(left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                }

            }
        }
        return result;
    }  
};