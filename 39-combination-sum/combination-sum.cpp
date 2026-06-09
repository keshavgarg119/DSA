class Solution {
public:
    void findCombinations(int i, vector<int>& candidates, int target, vector<int>& subset, vector<vector<int>>& result) {
        if(i==candidates.size()) {
            if(target==0) {
                result.push_back(subset);
            }
            return;
        }
        if(target >= candidates[i]) {
            subset.push_back(candidates[i]);
            findCombinations(i, candidates, target-candidates[i], subset, result);
            subset.pop_back();
        }
        findCombinations(i+1, candidates, target, subset, result);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>subset;
        vector<vector<int>>result;

        findCombinations(0, candidates, target, subset, result);
        return result;
    }
};