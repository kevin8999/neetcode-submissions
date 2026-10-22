class Solution {
public:
    bool hasUnique(vector<char>& input) {
        set<char> uniqueNums;
        vector<char> allNums;
        for (char c : input) {
            if (c != '.') {
                uniqueNums.insert(c);
                allNums.push_back(c);
            }
        }
        
        return (allNums.size() == uniqueNums.size());
    }

    bool rowsAreValid(vector<vector<char>>& board) {
        int i = 0;
        while (i < board.size()) {
            vector<char> row = board[i];
            if (!hasUnique(row))  return false;

            ++i;
        }
        return true;
    }

    bool colsAreValid(vector<vector<char>>& board) {
        for (int col = 0; col < board.size(); ++col) {
            vector<char> colValues(9);

            for (int row = 0; row < 9; ++row) {
                colValues[row] = board[row][col];
            }

            if (!hasUnique(colValues))  return false;
        }
        return true;
    }

    bool gridsAreValid(vector<vector<char>>& board) {
        for (int square = 0; square < 9; ++square) {
            int startRow = (square / 3) * 3;
            int startCol = (square % 3) * 3;

            vector<char> grid;
            for (int row = 0; row < 3; ++row) {
                for (int col = 0; col < 3; ++col) {
                    grid.push_back(board[startRow + row][startCol + col]);
                }
            }
            if (!hasUnique(grid))  return false;
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        return (rowsAreValid(board) and colsAreValid(board) and gridsAreValid(board));
    }
};
