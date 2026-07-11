class Solution {
  public:
    int ans = -1;
    int dr[4] = {-1,+1,0,0};
    int dc[4] = {0,0,-1,+1};
    
    void dfs(int i, int j, int xd, int yd, int n, int m, vector<vector<int>>& mat, vector<vector<bool>>& vis, int len) {
        if(i==xd && j==yd) {
            ans = max(ans, len);
        }
        
        vis[i][j] = true;
        
        for(int k=0; k<4; k++) {
            int nr = i + dr[k];
            int nc = j + dc[k];
            
            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && mat[nr][nc]==1) {
                dfs(nr, nc, xd, yd, n, m, mat, vis, len+1);
            }
        }
        
        vis[i][j] = false;
    }
    
    
    int longestPath(vector<vector<int>>& mat, int xs, int ys, int xd, int yd) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        
        if(mat[xs][ys]==0 || mat[xd][yd]==0) return -1;
        
        vector<vector<bool>>vis(n, vector<bool>(m,false));
        
        dfs(xs,ys,xd,yd,n,m,mat,vis,0);
        
        return ans;
        
    }
};