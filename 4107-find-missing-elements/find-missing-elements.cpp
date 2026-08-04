class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int maxi = INT_MIN;
        int mini = INT_MAX;

        unordered_set<int>st;

        for(int x: nums) {
            mini = min(x, mini);
            maxi = max(x, maxi);
            st.insert(x);
        }
        
        vector<int>ans;

        for(int i=mini+1; i<maxi; i++) {
            if(!st.count(i)) {
                ans.push_back(i);
            }
        }

        return ans;
        
    }
};