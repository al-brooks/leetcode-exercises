#ifndef Solution977_hpp
#define Solution977_hpp

/*
 Problem 977: Squares of a Sorted Array
 -> Given an integer array nums, sorted in increasing order,
    return an array of the squares of each number sorted in
    increasing order
 -> main thing to take into account is negative numbers
 */

#include <vector>
#include <cstdlib>

class Solution977 {
public:
    std::vector<int> sortedSquares(std::vector<int> &nums) {
        int n = (int) nums.size();
        int right = (int) n - 1;
        int left {0};
        std::vector<int> squares(n); // create vector of size n

        for (int i = n - 1; i >= 0; --i) {
          int square;
          if (abs(nums[left]) > abs(nums[right]) ) {
            square = nums[left];
            ++left;
          } else {
            square = nums[right];
            --right;
          }
          squares[i] = square * square; // can't use [] without allocating space on vector
        }

        return squares;
    }
};

#endif
