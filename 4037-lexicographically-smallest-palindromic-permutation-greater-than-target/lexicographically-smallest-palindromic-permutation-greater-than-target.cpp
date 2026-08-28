class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();

        // Frequency of characters
        vector<int> cnt(26, 0);

        for (char c : s) {
            cnt[c - 'a']++;
        }

        // A palindrome can have at most one odd frequency
        int odd = 0;
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                odd++;
                mid = char('a' + i);
            }
        }

        if (odd > 1)
            return "";

        // Number of characters available for left half
        vector<int> half(26);

        for (int i = 0; i < 26; i++) {
            half[i] = cnt[i] / 2;
        }

        int halfLen = n / 2;

        string left;

        // Checks whether the current prefix can be completed
        // into a palindrome > target.
        auto possible = [&]() -> bool {

            string temp = left;

            // Make the LARGEST possible remaining left half
            for (int c = 25; c >= 0; c--) {
                temp += string(half[c], char('a' + c));
            }

            // Construct the largest possible palindrome
            string palindrome = temp;

            if (n % 2)
                palindrome += mid;

            reverse(temp.begin(), temp.end());

            palindrome += temp;

            return palindrome > target;
        };

        // Build left half
        for (int pos = 0; pos < halfLen; pos++) {

            bool found = false;

            // Try smallest character first
            for (int c = 0; c < 26; c++) {

                if (half[c] == 0)
                    continue;

                // Temporarily use this character
                half[c]--;
                left.push_back(char('a' + c));

                // Can this choice lead to a valid answer?
                if (possible()) {
                    found = true;
                    break;
                }

                // Undo
                left.pop_back();
                half[c]++;
            }

            if (!found)
                return "";
        }

        // Construct final palindrome
        string ans = left;

        if (n % 2)
            ans += mid;

        reverse(left.begin(), left.end());
        ans += left;

        return ans > target ? ans : "";
    }
};