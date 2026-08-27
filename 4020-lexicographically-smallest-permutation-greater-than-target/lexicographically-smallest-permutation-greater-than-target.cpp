class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        // Frequency of characters in s
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        // Try to make the answer greater at position i.
        // We go from right to left so that we change the
        // latest possible position.
        for (int i = n - 1; i >= 0; i--) {

            // We need target[0 ... i-1] to remain unchanged.
            // Remove those characters from freq.
            vector<int> cnt = freq;

            bool possible = true;

            for (int j = 0; j < i; j++) {
                int x = target[j] - 'a';

                if (cnt[x] == 0) {
                    possible = false;
                    break;
                }

                cnt[x]--;
            }

            if (!possible)
                continue;

            // At position i, find the smallest character
            // strictly greater than target[i].
            int cur = target[i] - 'a';

            int bigger = -1;

            for (int c = cur + 1; c < 26; c++) {
                if (cnt[c] > 0) {
                    bigger = c;
                    break;
                }
            }

            if (bigger == -1)
                continue;

            // Use that character.
            cnt[bigger]--;

            string ans = target.substr(0, i);
            ans += char('a' + bigger);

            // Put all remaining characters in sorted order.
            for (int c = 0; c < 26; c++) {
                while (cnt[c] > 0) {
                    ans += char('a' + c);
                    cnt[c]--;
                }
            }

            return ans;
        }

        return "";
    }
};