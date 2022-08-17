#ifndef Solution36_hpp
#define Solution36_hpp

// Problem 36: Valid Sudoku
#include <vector>
#include <unordered_set>

using std::vector, std::unordered_set;

class Solution36 {
public:
    bool isValidSudoku1(vector<vector<char>> &board) {
        // note: board has a fixed width x length of 9x9
        vector<vector<int>> directions {
            // 9 RxC directions used in comparing 3x3 sub-boxes
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, -1}, {0, 0}, {0, 1},
            {1, -1}, {1, 0}, {1, 1}
        };
        
        // fixed mid points on Sudoku board - used to verify 3x3 sub-boxes
        vector<vector<int>> mid_pts {
            {1, 1}, {1, 4}, {1, 7},
            {4, 1}, {4, 4}, {4, 7},
            {7, 1}, {7, 4}, {7, 7}
        };
                
        unordered_set<char> vals;
        
        // iterate through each row and make sure digits aren't repeated
        for (int row = 0; row < board.size(); ++row) {
            for (char val: board[row]) {
                if (val == '.') {
                    continue;
                } else if (vals.find(val) != vals.end()) {
                    return false;
                } else {
                    vals.insert(val);
                }
            }
            vals.clear();
        }
        
        // iterate through each column
        for (int col = 0; col < board[0].size(); ++col) {
            for (int row = 0; row < board.size(); ++row) {
                char val = board[row][col];
                if (val == '.') {
                    continue;
                } else if (vals.find(val) != vals.end()) {
                    return false;
                } else {
                    vals.insert(val);
                }
            }
            vals.clear();
        }
        
        // check through sub-boxes
        for (int i = 0; i < mid_pts.size(); ++i) {
            int row = mid_pts[i][0];
            int col = mid_pts[i][1];
            for (int j = 0; j < directions.size(); ++j) {
                int new_row = row + directions[j][0];
                int new_col = col + directions[j][1];
                char val = board[new_row][new_col];
                if (val == '.') {
                    continue;
                } else if (vals.find(val) != vals.end()) {
                    return false;
                } else {
                    vals.insert(val);
                }
            }
            vals.clear();
        }
        
        
        return true;
    }
};


#endif /* Solution36_hpp */
