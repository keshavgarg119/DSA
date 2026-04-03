class Solution {
  public:
    vector<int> diagView(vector<vector<int>> mat) {
        int n = mat.size();
        vector<int> res;

        // Traverse all diagonals (i + j = constant)
        for (int d = 0; d <= 2 * (n - 1); d++) {
            for (int i = 0; i < n; i++) {
                int j = d - i;

                if (j >= 0 && j < n) {
                    res.push_back(mat[i][j]);
                }
            }
        }

        return res;
    }
};