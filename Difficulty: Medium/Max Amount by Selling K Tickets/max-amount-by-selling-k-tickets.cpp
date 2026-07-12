class Solution {
public:
    int maxAmount(vector<int>& arr, int k) {
        const int MOD = 1e9 + 7;

        priority_queue<int> pq;

        for (int x : arr)
            pq.push(x);

        long long ans = 0;

        while (k > 0 && !pq.empty()) {
            int node = pq.top();
            pq.pop();

            ans = (ans + node) % MOD;

            node--;

            if (node > 0)
                pq.push(node);

            k--;
        }

        return ans;
    }
};