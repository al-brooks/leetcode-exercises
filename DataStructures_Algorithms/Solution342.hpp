// Problem 342: Power of Four

#ifndef Solution342_hpp
#define Solution342_hpp

#include <cmath>

class Solution342 {
public:
    bool isPowerOfFour(int n) {
        while (n % 4 == 0 && n > 0) {
            n /= 4; // keep dividing by 4 as far as you can.
        }
        return n == 1; // 1 should be the final value
    }
};

#endif /* Solution342_hpp */
