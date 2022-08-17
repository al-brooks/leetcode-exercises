#ifndef Solution189_hpp
#define Solution189_hpp

// Problem 189: Rotate Array
#include <vector>

using std::vector;

class Solution189 {
public:
    // Went through multiple solutions:
    
    // Solution 1 - Using extra array
    void rotate1(vector<int> &nums, int k) {
        int len = (int) nums.size();
        vector<int> copy(len);
        for (int i = 0; i < len; ++i) {
            int new_idx = (i + k) % len;
            copy[new_idx] = nums[i];
        }
        for (int j = 0; j < len; ++j)
            nums[j] = copy[j];
    }
    
    // Solution 2
    // Multiple Reversals - Learned from LeetCode Solution
    void rotate2(vector<int> &nums, int k) {
        int len = (int) nums.size();
        k %= len; // if k is larger than length its value needs to be updated
        reverse(nums, 0, len - 1); // reverse entire array
        reverse(nums, 0, k - 1); // reverse "end shifted values" to make them in order
        reverse(nums, k, len - 1); // reverse original beginning values that are now at end

    }
    
    // Reverse Helper Function
    void reverse(vector<int> &nums, int start, int end) {
        while (start < end) {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            ++start;
            --end;
        }
    }
    
    // Solution 3
    // Cyclical Updates Using do while loop - Learned from Leetcode Solution
    void rotate3(vector<int> &nums, int k) {
        k %= nums.size();
        int count = 0;
        for (int start = 0; count < nums.size(); ++start) {
            int current = start;
            int prev = nums[start];
            do {
                int next = (current + k) % nums.size();
                int temp = nums[next];
                nums[next] = prev;
                prev = temp;
                current = next;
                ++count;
            } while (start != current);
        }
    }
};

#endif
