class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length();
        int ones = count(s.begin(), s.end(), '1');

        vector<pair<int,int>> zeroGroups; // {start, length}
        vector<int> zeroGroupIndex(n);
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                if (i > 0 && s[i - 1] == '0') zeroGroups.back().second++;
                else zeroGroups.push_back({i, 1});
            }
            zeroGroupIndex[i] = (int)zeroGroups.size() - 1;
        }

        if (zeroGroups.empty())
            return vector<int>(queries.size(), ones);

        // merge lengths of adjacent zero groups
        int m = (int)zeroGroups.size() - 1;
        vector<int> mergeLens(m);
        for (int i = 0; i < m; ++i)
            mergeLens[i] = zeroGroups[i].second + zeroGroups[i + 1].second;

        // sparse table over mergeLens for range-max queries
        int LOG = 1;
        while ((1 << LOG) < max(m, 1)) LOG++;
        vector<vector<int>> st(LOG + 1, vector<int>(max(m, 1), 0));
        if (m > 0) st[0] = mergeLens;
        for (int i = 1; i <= LOG; ++i)
            for (int j = 0; j + (1 << i) <= m; ++j)
                st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);

        auto rangeMax = [&](int l, int r) {
            int i = 31 - __builtin_clz(r - l + 1);
            return max(st[i][l], st[i][r - (1 << i) + 1]);
        };

        vector<int> ans;
        for (auto& q : queries) {
            int l = q[0], r = q[1];

            int left = zeroGroupIndex[l] == -1
                ? -1
                : zeroGroups[zeroGroupIndex[l]].second - (l - zeroGroups[zeroGroupIndex[l]].first);
            int right = zeroGroupIndex[r] == -1
                ? -1
                : r - zeroGroups[zeroGroupIndex[r]].first + 1;

            int startAdj = zeroGroupIndex[l] + 1;
            int endGroupIdx = (s[r] == '1') ? zeroGroupIndex[r] : zeroGroupIndex[r] - 1;
            int endAdj = endGroupIdx - 1;

            int activeSections = ones;

            if (s[l] == '0' && s[r] == '0' && zeroGroupIndex[l] + 1 == zeroGroupIndex[r]) {
                activeSections = max(activeSections, ones + left + right);
            } else if (startAdj <= endAdj) {
                activeSections = max(activeSections, ones + rangeMax(startAdj, endAdj));
            }

            if (s[l] == '0' && zeroGroupIndex[l] + 1 <= endGroupIdx) {
                activeSections = max(activeSections,
                    ones + left + zeroGroups[zeroGroupIndex[l] + 1].second);
            }

            if (s[r] == '0' && zeroGroupIndex[l] < zeroGroupIndex[r] - 1) {
                activeSections = max(activeSections,
                    ones + right + zeroGroups[zeroGroupIndex[r] - 1].second);
            }

            ans.push_back(activeSections);
        }

        return ans;
    }
};