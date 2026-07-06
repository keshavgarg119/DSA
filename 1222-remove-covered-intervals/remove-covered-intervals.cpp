class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int n = intervals.size();
        int start = intervals[0][0];
        int end = intervals[0][1];

        int ans = n;

        for(int i=1; i<n; i++) {
            if(intervals[i][0] > start && intervals[i][1] > end) {
                start = intervals[i][0];
                end = intervals[i][1];
                continue;
            }
            else if(intervals[i][0] >= start && intervals[i][1] <= end) {
                ans--;
            }
            else if(intervals[i][0] == start && intervals[i][1] >= end) {
                ans--;
                end = intervals[i][1];
            }
            else if(intervals[i][0] <= start && intervals[i][1] == end) {
                ans--;
            }
        }

        return ans;
    }
};