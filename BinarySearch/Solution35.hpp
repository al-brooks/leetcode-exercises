#ifndef Solution35_hpp
#define Solution35_hpp

// Problem 35: Search Insert Position
#include <vector>

class Solution35 {
public:
    int searchInsert(std::vector<int> &nums, int target) {
        int left {0};
        int right = (int) nums.size() - 1;
        int mid {0};

        while (left <= right) {
            mid = left + (right - left) / 2;
            if (target == nums[mid]) {
                return mid;
            } else if (target > nums[mid]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return left;
    }
};

#endif
