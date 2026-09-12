class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,vector<int>>mp;

        for(int i=0; i<nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        int ans = 0;

        for(auto &it: mp) {
            vector<int> indeces = it.second;

            if(indeces.size() == 3) {
                int i1 = indeces[0];
                int i2 = indeces[1];
                int i3 = indeces[2];

                if(i2-i1 == i3-i2) {
                    ans++;
                }
            }
        }

        return ans;
    }
};