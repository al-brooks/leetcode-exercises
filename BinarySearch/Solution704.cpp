/*
 Problem 704: Binary Search:
 -> Given an array of integers nums, which is sorted in
    ascending order, and an integer target in nums.
 -> If target exists then return its index, else return -1.
 -> You MUST write an algorithm in O(log n) runtime.
 */

#include <iostream>
#include <vector>

class Solution704 {
public:
    int search(std::vector<int> &nums, int target) {
        int pivot {0};
        int left {0};
        int right = (int) nums.size() - 1;

        while (left <= right) {
            pivot = left + (right - left) / 2;
            if (target == nums[pivot]) {
                return pivot;
            }
            if (target < nums[pivot]) {
                right = pivot - 1;
            }
            if (target > nums[pivot]) {
                left = pivot + 1;
            }
        }

        return -1;
    }
};

