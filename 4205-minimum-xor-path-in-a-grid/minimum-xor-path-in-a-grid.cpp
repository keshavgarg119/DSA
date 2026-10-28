
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        const int X = 1024;

        // dp[j][x] = whether XOR value x can reach current cell.
        vector<bitset<X>> dp(n);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                bitset<X> cur;

                if (i == 0 && j == 0) {
                    cur[grid[i][j]] = 1;
                } else {
                    if (i > 0) {
                        // dp[j] still stores the previous row.
                        for (int x = 0; x < X; x++) {
                            if (dp[j][x])
                                cur[x ^ grid[i][j]] = 1;
                        }
                    }

                    if (j > 0) {
                        // dp[j - 1] stores the current row's left cell.
                        for (int x = 0; x < X; x++) {
                            if (dp[j - 1][x])
                                cur[x ^ grid[i][j]] = 1;
                        }
                    }
                }

                dp[j] = cur;
            }
        }

        for (int x = 0; x < X; x++) {
            if (dp[n - 1][x])
                return x;
        }

        return -1;
    }
};
