class Solution {
public:
    // int solve(int i, int j, vector<vector<int>>& dp, string &word1, string &word2) {
    //     if(i<0) return j+1;
    //     if(j<0) return i+1;

    //     if(dp[i][j]!=-1) return dp[i][j];

    //     if(word1[i] == word2[j]) return solve(i-1,j-1, dp, word1, word2);

    //     return dp[i][j] = 1 + min(solve(i-1, j, dp, word1, word2), min(solve(i, j-1, dp, word1, word2), solve(i-1, j-1, dp, word1, word2)));
    // }
    // int minDistance(string word1, string word2) {
        // int n = word1.size();
        // int m = word2.size();

    //     vector<vector<int>>dp(n, vector<int>(m,-1));
    //     return solve(n-1,m-1,dp, word1, word2);
    // }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // vector<vector<int>>dp(n+1, vector<int>(m+1,0));
        vector<int>curr(m+1,0), prev(m+1,0);

        for(int j=0; j<=m; j++) prev[j] = j;

        for(int i=1; i<=n; i++) {
            curr[0] = i;
            for(int j=1; j<=m; j++) {
                if(word1[i-1] == word2[j-1]) {
                    curr[j] = prev[j-1];
                }
                else {
                    curr[j] = 1 + min(prev[j], min(curr[j-1], prev[j-1]));
                }
            }
            prev = curr;
        }

        return prev[m];
    }
};