class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

        // Store (value, original index)
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++)
            arr.push_back({nums[i], i});

        sort(arr.begin(), arr.end());

        // Position of each original index in the sorted array
        vector<int> pos(n);
        for (int i = 0; i < n; i++)
            pos[arr[i].second] = i;

        // Connected component of each position
        vector<int> comp(n);
        comp[0] = 0;

        for (int i = 1; i < n; i++) {
            if (arr[i].first - arr[i - 1].first <= maxDiff)
                comp[i] = comp[i - 1];
            else
                comp[i] = comp[i - 1] + 1;
        }

        // nxt[i] = furthest position reachable in one jump
        vector<int> nxt(n);
        int r = 0;

        for (int i = 0; i < n; i++) {
            while (r + 1 < n &&
                   arr[r + 1].first - arr[i].first <= maxDiff)
                r++;

            nxt[i] = r;
        }

        const int LOG = 20;
        vector<vector<int>> up(LOG, vector<int>(n));

        for (int i = 0; i < n; i++)
            up[0][i] = nxt[i];

        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                up[j][i] = up[j - 1][up[j - 1][i]];
            }
        }

        vector<int> ans;

        for (auto &q : queries) {

            int u = pos[q[0]];
            int v = pos[q[1]];

            if (u > v)
                swap(u, v);

            // Different connected components
            if (comp[u] != comp[v]) {
                ans.push_back(-1);
                continue;
            }

            // Same node
            if (u == v) {
                ans.push_back(0);
                continue;
            }

            int cur = u;
            int jumps = 0;

            for (int j = LOG - 1; j >= 0; j--) {
                if (up[j][cur] < v) {
                    cur = up[j][cur];
                    jumps += (1 << j);
                }
            }

            ans.push_back(jumps + 1);
        }

        return ans;
    }
};