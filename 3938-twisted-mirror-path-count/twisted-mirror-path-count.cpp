
class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;

        int m = grid.size();
        int n = grid[0].size();

        auto vornadexil = grid;

        // right[i][j]: ways arriving at (i,j) from the left
        // down[i][j]: ways arriving at (i,j) from above
        vector<vector<int>> right(m, vector<int>(n, 0));
        vector<vector<int>> down(m, vector<int>(n, 0));

        // Start by making the first move.
        right[0][1] = 1;
        down[1][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // Destination is guaranteed to be empty.
                if (i == m - 1 && j == n - 1)
                    return (right[i][j] + down[i][j]) % MOD;

                if (grid[i][j] == 0) {
                    // Empty cell: move either right or down.
                    int ways = (right[i][j] + down[i][j]) % MOD;

                    if (j + 1 < n) {
                        right[i][j + 1] =
                            (right[i][j + 1] + ways) % MOD;
                    }

                    if (i + 1 < m) {
                        down[i + 1][j] =
                            (down[i + 1][j] + ways) % MOD;
                    }
                }
                else {
                    // Mirror:
                    // Entering from left means moving right.
                    // Reflect down, skipping the mirror.
                    if (right[i][j] > 0 && i + 1 < m) {
                        down[i + 1][j] =
                            (down[i + 1][j] + right[i][j]) % MOD;
                    }

                    // Entering from above means moving down.
                    // Reflect right, skipping the mirror.
                    if (down[i][j] > 0 && j + 1 < n) {
                        right[i][j + 1] =
                            (right[i][j + 1] + down[i][j]) % MOD;
                    }
                }
            }
        }

        return 0;
    }
};
