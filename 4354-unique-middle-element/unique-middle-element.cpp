class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        unordered_map<int, int> freq;

        for (int x : nums){
            freq[x]++;
        }

        int mid = nums.size() / 2;

        return freq[nums[mid]] == 1;
    }
};