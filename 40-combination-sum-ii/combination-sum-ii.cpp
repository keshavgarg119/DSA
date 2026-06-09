class Solution {
public:
    void findCombinations(int index, vector<int>&candidates, int target, vector<int>& subset, vector<vector<int>>& ans) {
        if(target==0) {
            ans.push_back(subset);
            return;
        }

        for(int i = index; i<candidates.size(); i++) {
            if(i!=index && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;

            subset.push_back(candidates[i]);
            findCombinations(i+1, candidates, target-candidates[i], subset, ans);
            subset.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>subset;

        sort(candidates.begin(), candidates.end());
        findCombinations(0, candidates, target, subset, ans);

        return ans;
    }
};