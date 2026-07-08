class Solution {
public:
    void solve(int i, int j, vector<vector<int>>& mat, int n, int m, vector<vector<bool>>& vis) {

        vis[i][j] = true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        for(int k = 0; k < 4; k++) {

            int nr = i + dr[k];
            int nc = j + dc[k];

            if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;

            if(vis[nr][nc]) continue;

            if(mat[nr][nc] < mat[i][j]) continue;

            solve(nr, nc, mat, n, m, vis);
        }
    }

    int countCoordinates(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        vector<vector<bool>> p(n, vector<bool>(m, false));
        vector<vector<bool>> q(n, vector<bool>(m, false));

        for(int j = 0; j < m; j++) {
            solve(0, j, mat, n, m, p);
        }
        for(int i = 0; i < n; i++){
            solve(i, 0, mat, n, m, p);
        }
        
        for(int j = 0; j < m; j++) {
            solve(n - 1, j, mat, n, m, q);
        }
        for(int i = 0; i < n; i++){
            solve(i, m - 1, mat, n, m, q);
        }

        int ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(p[i][j] && q[i][j]) ans++;
            }
        }

        return ans;
    }
};