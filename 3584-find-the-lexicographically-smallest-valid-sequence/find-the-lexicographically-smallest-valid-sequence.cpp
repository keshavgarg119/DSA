class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> ans(m);

        // last[j] = position in word1 that can match word2[j]
        // while scanning from right to left
        vector<int> last(m, -1);

        int i = n - 1;
        int j = m - 1;

        while (i >= 0 && j >= 0) {
            if (word1[i] == word2[j]) {
                last[j] = i;
                j--;
            }
            i--;
        }

        // One mismatch is allowed
        bool canSkip = true;

        j = 0;

        for (i = 0; i < n; i++) {

            if (j == m)
                break;

            // Exact match
            if (word1[i] == word2[j]) {
                ans[j] = i;
                j++;
            }

            // Use our one allowed mismatch
            else if (canSkip &&
                    (j == m - 1 || i < last[j + 1])) {

                canSkip = false;

                ans[j] = i;
                j++;
            }
        }

        // Could not construct word2
        if (j != m)
            return {};

        return ans;
    }
};