class Solution {
public:
    bool solve(int index, int row, int col, vector<vector<char>>& board, string word) {

        if(index==word.length()) return true;
        //element doesnt exist
        if(row<0 || col<0 || row>=board.size() || col>=board[0].size()|| board[row][col] != word[index]) {
            return false;
        }

        char temp = board[row][col];

        board[row][col] = '#'; //marked visited

        bool found = solve(index+1, row+1, col, board, word) ||
                    solve(index+1, row-1, col, board, word) ||
                    solve(index+1, row, col+1, board, word) ||
                    solve(index+1, row, col-1, board, word);

        board[row][col] = temp;

        return found;

    }
    bool exist(vector<vector<char>>& board, string word) {

        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                if(board[i][j]==word[0]) {
                    if(solve(0, i, j, board, word)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};