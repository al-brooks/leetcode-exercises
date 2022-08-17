#ifndef Solution278_hpp
#define Solution278_hpp

// Problem 278: First Bad Version:

class Solution278 {
public:
    // isBadVersion Prototype - provided by LeetCode
    bool isBadVersion(int version);

    // solution:
    int firstBadVersion(int n) {
      int left {1};
      int right {n};

      while (left <= right) {
        int mid = left + (right - left) / 2;
        if (isBadVersion(mid)) {
          right = mid;
        } else {
          left = mid + 1;
        }
      }

      return left;
    }
};

#endif
