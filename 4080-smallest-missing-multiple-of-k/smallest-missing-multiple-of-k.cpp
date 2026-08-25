class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>st;

        for(int i=0; i<nums.size(); i++) {
            st.insert(nums[i]);
        }
        
        for(int i=1; ; i++) {
            int x = k*i;

            if(st.count(x)==0) {
                return x;
            }
        }
    }
};