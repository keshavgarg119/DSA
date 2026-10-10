
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1,
                               vector<int>& nums2,
                               int k1, int k2) {
        int n = nums1.size();
        long long k = 1LL * k1 + k2;

        vector<int> diff(n);
        int mx = 0;
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            mx = max(mx, diff[i]);
            sum += diff[i];
        }

        if (sum <= k) return 0;

        int left = 0, right = mx;

        // Find the minimum maximum difference x
        // achievable using at most k operations.
        while (left < right) {
            int mid = left + (right - left) / 2;
            long long need = 0;

            for (int d : diff) {
                if (d > mid)
                    need += d - mid;
            }

            if (need <= k)
                right = mid;
            else
                left = mid + 1;
        }

        int x = left;
        long long used = 0;
        long long ans = 0;

        // Reduce every difference to at most x.
        for (int d : diff) {
            int reduced = min(d, x);
            used += d - reduced;
            ans += 1LL * reduced * reduced;
        }

        // Use remaining operations to reduce x to x - 1.
        long long remaining = k - used;

        for (int d : diff) {
            if (remaining == 0) break;

            if (d >= x && x > 0) {
                ans -= 1LL * x * x;
                ans += 1LL * (x - 1) * (x - 1);
                remaining--;
            }
        }

        return ans;
    }
};
