class Solution {
public:
    void combinations(int index, int n, int k, vector<int>& subset, vector<vector<int>>& ans) {
        if(subset.size()==k) {
            ans.push_back(subset);
            return;
        }

        for(int i=index; i<=n; i++) {
            subset.push_back(i);
            combinations(i+1, n, k, subset, ans);
            subset.pop_back();
        }
        
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>subset;
        vector<vector<int>>ans;

        combinations(1, n, k, subset, ans);

        return ans;
    }
};