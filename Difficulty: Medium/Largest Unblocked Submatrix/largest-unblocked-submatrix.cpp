class Solution {
  public:
    int largestArea(int n, int m, int k, vector<vector<int>> &arr) {
        // code here
        
        if (k == 0) return n * m;
            
        vector<int>rows, cols;
        for(auto &x: arr) {
            rows.push_back(x[0]);
            cols.push_back(x[1]);
        }
        
        sort(rows.begin(), rows.end());
        sort(cols.begin(), cols.end());
        
        auto maxgap = [](vector<int>& v, int limit) {
            int ans = 0;
            
            ans = max(ans, v[0]-1);
            
            for(int i=1; i<v.size(); i++) {
                ans =  max(ans, v[i]-v[i-1]-1);
            }
            
            ans = max(ans, limit-v.back());
            
            return ans;
        };
        
        int maxRow = maxgap(rows,n);
        int maxCol = maxgap(cols,m);
        
        return maxRow*maxCol;
    }
};