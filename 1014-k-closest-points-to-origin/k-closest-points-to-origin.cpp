class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> pq;

        for(auto point: points) {
            int x = point[0];
            int y = point[1];

            int distance = x*x + y*y;
            pq.push({distance, point});
        }

        vector<vector<int>>ans;

        while(k>0) {
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }

        return ans;
    }
};