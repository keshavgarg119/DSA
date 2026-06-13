class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0, count0 = 0;
        int candidate1 = 0, candidate0 = 0;

        for(int num: nums) {
            if(num == candidate1) {
                count1++;
            }
            else if(num == candidate0) {
                count0++;
            }
            else if(count0 == 0) {
                candidate0 = num;
                count0++;
            }
            else if(count1 == 0) {
                candidate1 = num;
                count1++;
            }
            else {
                count0--;
                count1--;
            }
        }

        count0 = 0;
        count1 = 0;

        for(int i=0; i<nums.size(); i++) {
            if(nums[i]==candidate0) {
                count0++;
            }
            else if(nums[i]==candidate1) {
                count1++;
            }
        }

        int threshold = nums.size()/3;
        vector<int>ans;

        if(count0 > threshold) {
            ans.push_back(candidate0);
        }
        if(count1 > threshold) {
            ans.push_back(candidate1);
        }

        return ans;
    }
};