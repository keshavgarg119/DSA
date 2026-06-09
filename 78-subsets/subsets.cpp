class Solution {
public:
    void printSubSets(int index, vector<int>& nums, vector<int> &curr, vector<vector<int>>& result) {
        if(index==nums.size()) {
            result.push_back(curr);
            return;
        }

        curr.push_back(nums[index]);
        printSubSets(index+1, nums, curr, result);

        curr.pop_back();
        printSubSets(index+1, nums, curr, result);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>curr;
        vector<vector<int>>result;

        printSubSets(0, nums, curr, result);

        return result; 
    }
};