class Solution {
public:

    long long gcd(long long a, long long b) {
        while (b) {
            long long temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }

    long long count(long long x, vector<int>& coins) {
        int n = coins.size();
        long long ans = 0;

        // Enumerate all non-empty subsets
        for (int mask = 1; mask < (1 << n); mask++) {

            long long L = 1;
            int bits = 0;

            for (int i = 0; i < n; i++) {

                if (mask & (1 << i)) {

                    bits++;

                    L = lcm(L, coins[i]);

                    // No multiple of L can be <= x
                    if (L > x) {
                        break;
                    }
                }
            }

            if (L > x)
                continue;

            long long multiples = x / L;

            if (bits % 2 == 1)
                ans += multiples;
            else
                ans -= multiples;
        }

        return ans;
    }

    long long findKthSmallest(vector<int>& coins, int k) {

        long long low = 1;

        // kth amount can never be greater than
        // k * smallest coin
        long long high = 1LL * k * (*min_element(coins.begin(), coins.end()));

        while (low < high) {

            long long mid = low + (high - low) / 2;

            if (count(mid, coins) >= k) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};