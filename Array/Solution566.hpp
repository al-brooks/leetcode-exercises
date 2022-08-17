#ifndef Solution566_hpp
#define Solution566_hpp

// Problem 566: Reshape the Matrix
#include <vector>
#include <queue>

using std::vector, std::queue;

class Solution566 {
public:
    // Method 1: Using a Queue
    vector<vector<int>> matrixReshape1(vector<vector<int>> &mat, int r, int c) {
        // Input may not correctly line up given rows and cols
        if (mat.size() == 0 || (r * c) != (mat.size() * mat[0].size()))
            return mat;
            
        queue<int> val;
        vector<vector<int>> result(r, vector<int> (c, 0)); // Initialize empty 2-D vector
        
        for (int i = 0; i < mat.size(); ++i) {
            for (int j = 0; j < mat[i].size(); ++j) {
                val.push(mat[i][j]);
            }
        }
        
        for (int row = 0; row < r; ++row) {
            for (int col = 0; col < c; ++col) {
                result[row][col] = val.front();
                val.pop();
            }
        }
        
        return result;
    }
    
    // Method 2: Updating Return Array While Reading Input
    vector<vector<int>> matrixReshape2(vector<vector<int>> &mat, int r, int c) {
        if (mat.size() == 0 || (r * c) != (mat.size() * mat[0].size()))
            return mat;
        
        vector<vector<int>> result(r, vector<int>(c, 0));
        int row = r -1;
        int col = c - 1;
        for (int i = (int) mat.size() - 1; i > -1; --i) {
            for (int j = (int) mat[0].size() - 1; j > -1; --j) {
                result[row][col--] = mat[i][j];
                if (col < 0) {
                    --row;
                    col = c - 1;
                }
            }
        }
        
        return result;
    }
};


#endif /* Solution566_hpp */
