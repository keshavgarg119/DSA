class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pref(n);
        vector<int> suff(n);
        int var = nums[0];
        for (int i = 0; i < n; i++) {
            var = max(var, nums[i]);
            pref[i] = var;
        }
        var = nums[n - 1];
        for (int i = n - 1; i >= 0; i--) {
            var = min(var, nums[i]);
            suff[i] = var;
        }
        for (int i = 0; i < n; i++) {
            if (pref[i] - suff[i] <= k) {
                return i;
            }
        }
        return -1;
    }
};