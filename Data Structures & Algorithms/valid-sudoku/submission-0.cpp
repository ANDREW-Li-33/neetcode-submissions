class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, int> row_map[9];
        unordered_map<int, int> col_map[9];
        unordered_map<int, int> square_map[9];
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == '.') continue;
                if (++row_map[i][board[i][j]] > 1) return false;
                if (++col_map[j][board[i][j]] > 1) return false;
                int current_square = (i / 3) * 3 + (j / 3);
                if (++square_map[current_square][board[i][j]] > 1) return false;
            }
        }
        return true;
    }
};
