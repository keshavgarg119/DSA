class Solution {
public:
    unordered_set<string>st;
    vector<int>dp;

    bool solve(int start, string &s) {
        if(start==s.length()) return true;

        if(dp[start]!=-1) return dp[start];

        string curr = "";

        for(int end = start; end<s.length(); end++) {
            curr += s[end];

            if(st.count(curr) && solve(end+1, s)) { // found  in dictionory, then recurse
                return dp[start] = true;
            }
        }

        return dp[start] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        st = unordered_set<string>(wordDict.begin(), wordDict.end());

        dp.resize(s.length(), -1);

        return solve(0,s);
    }
};