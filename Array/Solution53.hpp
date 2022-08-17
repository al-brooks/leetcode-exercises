#ifndef Solution53_hpp
#define Solution53_hpp

/*
     Problem 53: Maximum Subarray:
     -> Given an integer array nums, find the contiguous subarray
        (containing at least one number) which has the largest
        sum.
     -> Return its sum
 */

#include <iostream>
#include <vector>

class Solution53 {
public:
    int maxSubArray(std::vector<int> &nums) {
        int currSum {nums[0]};
        int max {nums[0]};
        
        for (int i {1}; i < nums.size(); ++i) {
            if (currSum < 0) {
                currSum = nums[i];
            } else {
                currSum += nums[i];
            }
            
            if (currSum > max)
                max = currSum;
        }
        
        return max;
    }
};



#endif /* Solution53_hpp */
