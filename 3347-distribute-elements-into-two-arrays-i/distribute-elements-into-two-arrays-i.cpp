class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();

        vector<int>arr1, arr2;

        for(int i=0; i<n; i++) {
            if(i==0) arr1.push_back(nums[i]);
            else if(i==1) arr2.push_back(nums[i]);
            else {
                if(arr1.back() > arr2.back()) {
                    arr1.push_back(nums[i]);
                }
                else {
                    arr2.push_back(nums[i]);
                }
            }
        }

        for(int i=0; i<arr2.size(); i++) {
            arr1.push_back(arr2[i]);
        }

        return arr1;
    }
};