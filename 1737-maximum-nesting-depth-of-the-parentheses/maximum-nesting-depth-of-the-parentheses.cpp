class Solution {
public:
    int maxDepth(string s) {
        int count = 0, ans = 0;

        int n = s.length();

        for(int i=0; i<n; i++) {
            if(s[i] == '(') {
                count++;
                ans = max(ans, count);
            }
            else if(s[i] == ')') {
                count--;
            }
        }

        return ans;
    }
};