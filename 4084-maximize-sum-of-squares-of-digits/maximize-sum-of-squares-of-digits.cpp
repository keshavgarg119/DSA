class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (1LL * num * 9 < sum)
            return "";

        string ans;
        int nines = sum / 9;
        int rem = sum % 9;

        ans += string(nines, '9');

        if (rem > 0)
            ans += char('0' + rem);

        ans += string(num - ans.size(), '0');

        return ans;
    }
};