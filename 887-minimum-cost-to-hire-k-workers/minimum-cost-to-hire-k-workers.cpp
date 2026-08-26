class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality,
                                 vector<int>& wage,
                                 int k) {

        int n = quality.size();

        // {ratio, quality}
        vector<pair<double, int>> workers;

        for(int i = 0; i < n; i++) {
            double ratio = (double)wage[i] / quality[i];

            workers.push_back({ratio, quality[i]});
        }

        // Sort by wage / quality ratio
        sort(workers.begin(), workers.end());

        // Max heap of qualities
        priority_queue<int> pq;

        int qualitySum = 0;
        double ans = DBL_MAX;

        for(auto [ratio, q] : workers) {

            // Add current worker
            pq.push(q);
            qualitySum += q;

            // Keep only k smallest qualities
            if(pq.size() > k) {
                qualitySum -= pq.top();
                pq.pop();
            }

            // Exactly k workers
            if(pq.size() == k) {
                double cost = ratio * qualitySum;

                ans = min(ans, cost);
            }
        }

        return ans;
    }
};