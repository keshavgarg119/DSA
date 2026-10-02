class Solution {
public:
    void solve(int open, int close, int n, string curr, vector<string>& result) {
        if(curr.size() == 2*n) {
            result.push_back(curr);
            return;
        }

        if(open < n) {
            solve(open+1, close, n, curr+"(", result);
        }

        if(close < open) {
            solve(open, close+1, n, curr+")", result);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>result;

        solve(0,0,n,"",result);

        return result;
    }
};