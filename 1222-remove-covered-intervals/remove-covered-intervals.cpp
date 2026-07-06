// class Solution {
// public:
//     int removeCoveredIntervals(vector<vector<int>>& intervals) {
//         sort(intervals.begin(), intervals.end());

//         int n = intervals.size();
//         int start = intervals[0][0];
//         int end = intervals[0][1];

//         int ans = n;

//         for(int i=1; i<n; i++) {
//             if(intervals[i][0] > start && intervals[i][1] > end) {
//                 start = intervals[i][0];
//                 end = intervals[i][1];
//                 continue;
//             }
//             else if(intervals[i][0] >= start && intervals[i][1] <= end) {
//                 ans--;
//             }
//             else if(intervals[i][0] == start && intervals[i][1] >= end) {
//                 ans--;
//                 end = intervals[i][1];
//             }
//             else if(intervals[i][0] <= start && intervals[i][1] == end) {
//                 ans--;
//             }
//         }

//         return ans;
//     }
// };
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(),
        [](vector<int>& a, vector<int>& b){
            if(a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        });

        int ans = 1;
        int end = intervals[0][1];

        for(int i = 1; i < intervals.size(); i++) {

            if(intervals[i][1] > end) {
                ans++;
                end = intervals[i][1];
            }
        }

        return ans;
    }
};