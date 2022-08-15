// Problem 74: Search a 2D Matrix
#include <vector>

using std::vector;

class Solution74 {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int row = 0;
        int len = matrix[row].size();
        // check if target is less than the greatest value in this row
        while (target > matrix[row][len - 1] && (row + 1) < matrix.size()) {
            ++row;
        }
        
        // once we hit a row where the target is less than the greatest value
        // we know it's either in this row or it doesn't exist
        int start = 0;
        int end = len - 1;
        int mid = (end - start) / 2;
        while (start <= end) {
            if (target > matrix[row][mid]) {
                start = mid + 1;
                mid = start + (end - start) / 2;
            } else if (target < matrix[row][mid]) {
                end = mid - 1;
                mid = start + (end - start) / 2;
            } else {
                return true;
            }
        }
        
        return false;
    }
};
