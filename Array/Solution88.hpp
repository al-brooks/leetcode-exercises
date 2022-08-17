#ifndef Solution88_hpp
#define Solution88_hpp

// Problem 88: Merge Sorted Array
#include <vector>

using std::vector;

class Solution88 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ptr1 = m - 1; // end of first array values
        int ptr2 = n - 1; // end of second array
        int end = m + n - 1; // end of m + n array - fill in descending

        while (end >= 0) {
            if (ptr2 < 0) {
                break;
            } else if (ptr1 >= 0 && nums1[ptr1] > nums2[ptr2]) {
                // there are scenarios where ptr1 will be finished first
                nums1[end--] = nums1[ptr1--];
            } else {
                nums1[end--] = nums2[ptr2--];
            }
        }


    }
};



#endif /* Solution88_hpp */
