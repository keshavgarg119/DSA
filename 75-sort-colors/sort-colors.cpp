class Solution {
public:
    void sortColors(vector<int>& nums) {
        // int count0 = 0;
        // int count1 = 0;
        // int count2 = 0;

        // for(int i=0; i<nums.size(); i++) {
        //     if(nums[i]==0) {
        //         count0++;
        //     }
        //     else if(nums[i]==1) {
        //         count1++;
        //     }
        //     else {
        //         count2++;
        //     }
        // }

        // int index = 0;
        // while(count0>0) {
        //     nums[index] = 0;
        //     count0--;
        //     index++;
        // }
        // while(count1>0) {
        //     nums[index] = 1;
        //     count1--;
        //     index++;
        // }
        // while(count2>0) {
        //     nums[index] = 2;
        //     count2--;
        //     index++;
        // }
        int low = 0;
        int mid = 0;
        int high = nums.size()-1;

        while(mid<=high) {
            if(nums[mid]==0) {
                swap(nums[low], nums[mid]);
                mid++;
                low++;
            }
            else if(nums[mid]==1) {
                mid++;
            }
            else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};