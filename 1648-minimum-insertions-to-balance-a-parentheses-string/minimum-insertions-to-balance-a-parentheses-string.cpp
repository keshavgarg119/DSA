class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        int open = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                open++;
            } else {
                // Ensure we have a pair of consecutive ')'
                if (i + 1 < s.size() && s[i + 1] == ')') {
                    i++;  // Consume the second ')'
                } else {
                    ans++; // Insert the missing ')'
                }

                // Match this '))' pair with an opening '('
                if (open > 0) {
                    open--;
                } else {
                    ans++; // Insert a missing '('
                }
            }
        }

        // Each unmatched '(' needs two closing ')'
        ans += 2 * open;

        return ans;
    }
};