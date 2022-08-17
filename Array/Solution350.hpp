#ifndef Solution350_hpp
#define Solution350_hpp

// Problem 350: Intersection of Two Arrays II

#include <vector>
#include <unordered_map>

using std::vector, std::unordered_map;

class Solution350 {
public:
    // accepted
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        unordered_map<int, int> num_map;

        // we want to use the hash map on the smaller array
        // this increased speed from 28% to 63%!
        // while using less memory
        if (nums1.size() > nums2.size()) {
            return intersect(nums2, nums1);
        }

        for (int i = 0; i < nums1.size(); ++i) {
            ++num_map[nums1[i]];
        }

        int k = 0;
        for (int num: nums2) {
            auto it = num_map.find(num);
            if (it != num_map.end() && it->second > 0) {
                --it->second;
                nums1[k++] = num;
            }
        }

        // return first k elements of nums1 array - saving space
        // note: if it's okay to overwrite input array
        return vector(nums1.begin(), nums1.begin() + k);
    }
};


#endif /* Solution350_hpp */
