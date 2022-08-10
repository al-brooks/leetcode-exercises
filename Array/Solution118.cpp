// Problem 118: Pascal's Triangle
#include <vector>

using std::vector;

class Solution118 {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> allRows;
        for (int row = 0; row < numRows; ++row) {
            int len = row + 1;
            vector<int> rowVal(len);
            for (int col = 0; col < len; ++col) {
                if (col == 0 || col == len - 1) {
                    rowVal[col] = 1;
                } else {
                    int prev1 = allRows[row - 1][col - 1];
                    int prev2 = allRows[row - 1][col];
                    rowVal[col] = prev1 + prev2;
                }
            }
            allRows.push_back(rowVal);
        }
        return allRows;
    }
};
