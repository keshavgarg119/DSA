class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        auto solendivar = make_pair(s, queries); // required by the problem

        int n = s.size();

        vector<int> digits;
        vector<int> pos;

        // Store all non-zero digits and their original positions
        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                digits.push_back(s[i] - '0');
                pos.push_back(i);
            }
        }

        int m = digits.size();

        // prefix sum of digits
        vector<long long> prefSum(m + 1, 0);

        // powers of 10
        vector<long long> pow10(m + 1, 1);

        // prefix concatenated number
        vector<long long> prefNum(m + 1, 0);

        for (int i = 0; i < m; i++) {
            prefSum[i + 1] = prefSum[i] + digits[i];
            pow10[i + 1] = (pow10[i] * 10) % MOD;
            prefNum[i + 1] = (prefNum[i] * 10 + digits[i]) % MOD;
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            // first non-zero digit inside [l, r]
            int L = lower_bound(pos.begin(), pos.end(), l) - pos.begin();

            // last non-zero digit inside [l, r]
            int R = upper_bound(pos.begin(), pos.end(), r) - pos.begin() - 1;

            if (L > R) {
                ans.push_back(0);
                continue;
            }

            long long digitSum = prefSum[R + 1] - prefSum[L];

            int len = R - L + 1;

            long long number =
                (prefNum[R + 1] -
                 prefNum[L] * pow10[len] % MOD + MOD) % MOD;

            ans.push_back((number * digitSum) % MOD);
        }

        return ans;
    }
};