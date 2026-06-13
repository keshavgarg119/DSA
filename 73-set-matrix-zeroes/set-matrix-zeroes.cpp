class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix[0].size();
        int m = matrix.size();

        //Time complexity: O(m*n)
        //Space Complexity: O(m+n)

        // vector<int>row(m,0);
        // vector<int>col(n,0);

        // for(int i=0; i<m; i++) {
        //     for(int j=0; j<n; j++) {
        //         if(matrix[i][j]==0) {
        //             row[i] = 1;
        //             col[j] = 1;
        //         }
        //     }
        // }

        // for(int i=0; i<m; i++) {
        //     for(int j=0; j<n; j++) {
        //         if(row[i]==1 || col[j]==1) {
        //             matrix[i][j] = 0;
        //         }
        //     }
        // }
//...............................................................................
        // Optimal approach for space complexity
        bool firstrow = false;
        bool firstcol = false;

        for(int i=0; i<m; i++) {
            if(matrix[i][0]==0) {
                firstcol = true;
                break;
            }
        }

        for(int j=0; j<n; j++) {
            if(matrix[0][j]==0) {
                firstrow = true;
                break;
            }
        }

        
        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                if(matrix[i][j]==0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                if(matrix[i][0]==0 || matrix[0][j]==0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if(firstrow) {
            for(int j=0; j<n; j++) {
                matrix[0][j] = 0;
            }
        }

        if(firstcol) {
            for(int i=0; i<m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};