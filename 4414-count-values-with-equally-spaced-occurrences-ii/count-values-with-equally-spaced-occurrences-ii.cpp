class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, vector<int>>mp;

        for(int i=0; i<nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        int ans = 0;

        for(auto &it: mp) {
            vector<int> &indeces = it.second;

            if(indeces.size() < 3) {
                continue;
            }

            int gap = indeces[1] - indeces[0];

            bool select = true;

            for(int i=2; i<indeces.size(); i++) {
                if(indeces[i] - indeces[i-1] != gap) {
                    select = false;
                    break;
                }
            }

            if(select) ans++;
        }

        return ans;
    }
};