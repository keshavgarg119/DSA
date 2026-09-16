class Solution {
public:
    static const int MOD = 1e9 + 7;

    int numberOfSets(int n, int k) {
        long long ans = 1;

        // C(n + k - 1, 2k)
        for (int i = 1; i <= 2 * k; i++) {
            ans = ans * (n + k - i) % MOD;

            // Modular inverse of i using Fermat's theorem
            ans = ans * modPow(i, MOD - 2) % MOD;
        }

        return ans;
    }

private:
    long long modPow(long long a, long long b) {
        long long result = 1;

        while (b > 0) {
            if (b & 1)
                result = result * a % MOD;

            a = a * a % MOD;
            b >>= 1;
        }

        return result;
    }
};