class Solution {
public:
    // unordered_set<string>st;
    // vector<int>dp;

    // bool solve(int start, string &s) {
    //     if(start==s.length()) return true;

    //     if(dp[start]!=-1) return dp[start];

    //     string curr = "";

    //     for(int end = start; end<s.length(); end++) {
    //         curr += s[end];

    //         if(st.count(curr) && solve(end+1, s)) { // found  in dictionory, then recurse
    //             return dp[start] = true;
    //         }
    //     }

    //     return dp[start] = false;
    // }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st(wordDict.begin(), wordDict.end());
        int n = s.length();
        vector<bool>dp(n+1, false);

        dp[0] = true;
        for(int i=0; i<=n; i++) {
            for(int j=0; j<i; j++) {
                if(dp[j] && st.count(s.substr(j,i-j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};