class Solution {
public:
    bool isSafe(int row, int col, vector<string>& board, int n) {
        int dupRow = row;
        int dupCol = col;

        //check diagonal
        while(row>=0 && col>=0) {
            if(board[row][col]=='Q') {
                return false;
            }
            row--;
            col--;
        }

        row = dupRow;
        col = dupCol;
        //check col
        while(col>=0) {
            if(board[row][col]=='Q') return false;
            col--;
        }

        row = dupRow;
        col = dupCol;
        //check row
        while(row<n && col>=0) {
            if(board[row][col]=='Q') return false;
            row++;
            col--;
        }

        return true;
    }
    void solve(int col, int n, vector<string>& board, vector<vector<string>>& result) {
        if(col==n) {
            result.push_back(board);
            return;
        }

        for(int row=0; row<n; row++) {
            if(isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                solve(col+1, n, board, result);
                board[row][col] = '.';
            }
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n);
        vector<vector<string>>result;

        string s(n, '.');

        for(int i=0; i<n; i++) {
            board[i] = s;
        }

        solve(0, n, board, result);

        return result;
    }
};