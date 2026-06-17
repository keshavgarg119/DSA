class Solution {
public:
    char processStr(string s, long long k) {

        int n = s.size();
        vector<long long> len(n);

        long long currLen = 0;

        // Step 1: compute lengths
        for(int i = 0; i < n; i++) {

            char ch = s[i];

            if(ch == '*') {

                if(currLen > 0) {
                    currLen--;
                }
            }

            else if(ch == '#') {
                currLen *= 2;
            }

            else if(ch == '%') {
                // length unchanged
            }

            else {
                currLen++;
            }

            len[i] = currLen;
        }

        // out of bounds
        if(k >= currLen) {
            return '.';
        }

        // Step 2: go backward
        for(int i = n - 1; i >= 0; i--) {

            char ch = s[i];
            long long curr = len[i];

            if(ch == '#') {

                long long half = curr / 2;
                k %= half;
            }

            else if(ch == '%') {

                k = curr - 1 - k;
            }

            else if(ch == '*') {
                // nothing
            }

            else {

                if(k == curr - 1) {
                    return ch;
                }
            }
        }

        return '.';
    }
};