// Problem 1: Two Sum

#include <vector>
#include <unordered_map>

using std::vector, std::unordered_map;

class Solution1 {
public:
    // solution accepted - Time O(n) Space O(n)
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> result;
        unordered_map<int, int> diff;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (diff.find(nums[i]) != diff.end()) {
                result.push_back(diff[nums[i]]);
                result.push_back(i);
            } else {
                int diff_val = target - nums[i];
                diff.insert({diff_val, i});
            }
        }
        
        return result;
    }
};

