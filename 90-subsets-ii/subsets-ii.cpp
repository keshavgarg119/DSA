class Solution {
public:
    void printSSwithNoDup(int index, vector<int> &nums, vector<int>& subset, vector<vector<int>>& result) {
        result.push_back(subset);

        for(int i=index; i<nums.size(); i++) {
            if(i!=index && nums[i]==nums[i-1]) {
                continue;
            }
            subset.push_back(nums[i]);
            printSSwithNoDup(i+1, nums, subset, result);
            subset.pop_back();

        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>subset;
        vector<vector<int>>result;
        sort(nums.begin(), nums.end());
        
        printSSwithNoDup(0, nums, subset, result);

        return result;
    }
};