#ifndef Solution283_hpp
#define Solution283_hpp

// Problem 283 - Move Zeroes
#include <vector>
#include <algorithm>

using std::vector;

class Solution283 {
public:
    // Method 1: Use Extra Array and Count Zeroes
    void moveZeroes1(vector<int> &nums) {
        int len = (int) nums.size();
        int count_zeros = 0;
        for (int i = 0; i < len; ++i) {
            if (!nums[i])
                ++count_zeros;
        }
        vector<int> result;
        for (int i = 0; i < len; ++i) {
            if (nums[i])
                result.push_back(nums[i]);
        }

        for (int i = 0; i < count_zeros; ++i) {
            result.push_back(0);
        }

        nums = result;

    }

    // Method 2: Overwrite Array using 2 Iterations
    void moveZeroes2(vector<int> &nums) {
        int len = (int) nums.size();
        int last_idx = 0;

        for (int i = 0; i < len; ++i) {
            if (nums[i]) {
                nums[last_idx++] = nums[i];
            }
        }

        // add 0's after last known non-zero index
        for (int i = last_idx; i < nums.size(); ++i) {
            nums[i] = 0;
        }
    }

};

#endif
