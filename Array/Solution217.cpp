/*
  Problem 217: Contains Duplicate:
  -> Given an integer array nums, return true if any value
     appears at least twice in the array.
  -> return false if every element is distinct
*/

#include <iostream>
#include <vector>
#include <unordered_set>


class Solution217 {
public:
    bool containsDuplicate(std::vector<int> &nums) {
        // You have to iterate through the entire array
        // in worst case - all values are distinct
        std::unordered_set<int> vals;
        
        for (int i {0}; i < nums.size(); ++i) {
            if (vals.find(nums[i]) != vals.end()) {
                return true;
            } else {
                vals.insert(nums[i]);
            }
        }
        
        return false;
    }
};
