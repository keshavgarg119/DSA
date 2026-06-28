class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        sort(occupiedIntervals.begin(), occupiedIntervals.end());

        vector<vector<int>> merged;

        for (auto &in : occupiedIntervals) {
            if (merged.empty() || in[0] > merged.back()[1] + 1) {
                merged.push_back(in);
            } else {
                merged.back()[1] = max(merged.back()[1], in[1]);
            }
        }

        vector<vector<int>> ans;

        for (auto &in : merged) {

            int l = in[0];
            int r = in[1];

            // No overlap
            if (r < freeStart || l > freeEnd) {
                ans.push_back({l, r});
                continue;
            }

            // Left part survives
            if (l < freeStart) {
                ans.push_back({l, freeStart - 1});
            }

            // Right part survives
            if (r > freeEnd) {
                ans.push_back({freeEnd + 1, r});
            }
        }

        return ans;
    }
};