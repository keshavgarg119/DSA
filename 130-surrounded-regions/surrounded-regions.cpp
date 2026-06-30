class Solution {
public:
    int n, m;
    int dr[4] = {-1,1,0,0};
    int dc[4] = {0,0,-1,1};

    void dfs(int r, int c, vector<vector<bool>>& vis, vector<vector<char>>& board) {

        vis[r][c] = true;

        for(int k=0; k<4; k++) {
            int nr = dr[k] + r;
            int nc = dc[k] + c;

            if(nr<n && nr>=0 && nc<m && nc>=0 && !vis[nr][nc] && board[nr][nc]=='O') {
                dfs(nr,nc,vis,board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();

        vector<vector<bool>>vis(n, vector<bool>(m,false));

        for(int i=0; i<n; i++) {
            if(!vis[i][0] && board[i][0]=='O') {
                dfs(i,0,vis,board);
            }
            if(!vis[i][m-1] && board[i][m-1]=='O') {
                dfs(i,m-1,vis,board);
            }
        }

        for(int j=0; j<m; j++) {
            if(!vis[0][j] && board[0][j]=='O') {
                dfs(0,j,vis,board);
            }
            if(!vis[n-1][j] && board[n-1][j]=='O') {
                dfs(n-1,j,vis,board);
            }
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!vis[i][j] && board[i][j]=='O') {
                    board[i][j] = 'X';
                }
            }
        }

    }
};