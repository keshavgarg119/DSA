class Solution {
  public:
    int waysToIncreaseLCSBy1(string &s1, string &s2) {
        // code here
        int n = s1.size();
        int m = s2.size();
        
        vector<vector<int>>f(n+1, vector<int>(m+1,0));
        vector<vector<int>>b(n+1, vector<int>(m+1,0));
        
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(s1[i-1] == s2[j-1]) {
                    f[i][j] = 1 + f[i-1][j-1];
                }
                else {
                    f[i][j] = max(f[i-1][j], f[i][j-1]);
                }
            }
        }
        
        for(int i=n-1; i>=0; i--) {
            for(int j=m-1; j>=0; j--) {
                if(s1[i] == s2[j]) {
                    b[i][j] = 1 + b[i+1][j+1];
                }
                else {
                    b[i][j] = max(b[i+1][j], b[i][j+1]);
                }
            }
        }
        
        int L = f[n][m];
        int ans = 0;

        for (int i = 0; i <= n; i++) {
            vector<bool> used(26, false);

            for (int j = 0; j < m; j++) {
                int ch = s2[j] - 'a';

                if (used[ch]) continue;

                if (f[i][j] + 1 + b[i][j + 1] == L + 1) {
                    ans++;
                    used[ch] = true;
                }
            }
        }

        return ans;
        
    }
};
