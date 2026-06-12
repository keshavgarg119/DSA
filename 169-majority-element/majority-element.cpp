class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // unordered_map<int, int>mp;
        int n = nums.size();

        // for(int i: nums) {
        //     mp[i]++;

        //     if(mp[i]>n/2) return i; 
        // }

        // return -1;

        int ans = 0, freq = 0;
        for(int i=0; i<n; i++) {
            if(freq==0) {
                ans = nums[i];
            }

            if(ans == nums[i]) {
                freq++;
            }
            else {
                freq--;
            }
        }

        return ans;
    }
};