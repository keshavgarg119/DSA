class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();

        vector<pair<int,int>>project;

        for(int i=0; i<n; i++) {
            project.push_back({capital[i], profits[i]});
        }

        sort(project.begin(), project.end());

        priority_queue<int>pq;

        int i = 0;
        while(k>0) {

            while(i<n && project[i].first<=w) {
                pq.push(project[i].second);
                i++;
            }

            if(pq.empty()) break;

            w += pq.top();
            pq.pop();
            k--;
           
        }

        return w;
    }
};