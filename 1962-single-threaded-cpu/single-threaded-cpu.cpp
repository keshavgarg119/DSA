class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<vector<int>>newTasks;
        int n = tasks.size();

        for(int i=0; i<n; i++) {
            newTasks.push_back({
                tasks[i][0], //enqueue time
                tasks[i][1], // processing time
                i            // original index
            });
        }

        sort(newTasks.begin(), newTasks.end());

        // {processing time, index}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        vector<int>ans;

        long long currentTime = 0;
        int i = 0;

        while(i<n || !pq.empty()) {

            //idle state
            if(pq.empty() && currentTime <  newTasks[i][0]) {
                currentTime = newTasks[i][0];
            }

            // add available tasks
            while(i<n && newTasks[i][0] <= currentTime) {
                pq.push({
                    newTasks[i][1],
                    newTasks[i][2]
                });
                i++;
            }

            //process task
            auto top = pq.top();
            pq.pop();

            int processingTime = top.first;
            int index = top.second;

            currentTime += processingTime;

            ans.push_back(index);
        }

        return ans;
    }
};