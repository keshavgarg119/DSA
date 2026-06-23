class Solution {
public:
    static const int MOD = 1e9 + 7;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        vector<long long> up(m + 1, 0), down(m + 1, 0);

        // Base: length = 2
        for (int x = 1; x <= m; x++) {
            up[x] = m - x;     // choose larger previous value
            down[x] = x - 1;   // choose smaller previous value
        }

        for (int len = 3; len <= n; len++) {

            vector<long long> newUp(m + 1, 0);
            vector<long long> newDown(m + 1, 0);

            long long pref = 0;

            // newDown[x] = sum(up[y]) for y < x
            for (int x = 1; x <= m; x++) {
                newDown[x] = pref;
                pref = (pref + up[x]) % MOD;
            }

            long long suff = 0;

            // newUp[x] = sum(down[y]) for y > x
            for (int x = m; x >= 1; x--) {
                newUp[x] = suff;
                suff = (suff + down[x]) % MOD;
            }

            up = move(newUp);
            down = move(newDown);
        }

        long long ans = 0;

        for (int x = 1; x <= m; x++) {
            ans = (ans + up[x] + down[x]) % MOD;
        }

        return (int)ans;
    }
};