class Solution {
public:
    static constexpr int MOD = 1e9 + 7;
    int n;
    vector<int> nums;
    int memo[201][201][201];

    int dfs(int i, int g1, int g2) {
        if (i == n)
            return (g1 && g1 == g2);

        int &res = memo[i][g1][g2];
        if (res != -1) return res;

        long long ans = 0;

        // Skip
        ans += dfs(i + 1, g1, g2);

        // Put into seq1
        ans += dfs(i + 1, gcd(g1, nums[i]), g2);

        // Put into seq2
        ans += dfs(i + 1, g1, gcd(g2, nums[i]));

        return res = ans % MOD;
    }

    int subsequencePairCount(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        memset(memo, -1, sizeof(memo));
        return dfs(0, 0, 0);
    }
};