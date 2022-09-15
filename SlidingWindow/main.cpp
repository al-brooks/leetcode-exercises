#include "Solution3.hpp"
#include "Solution567.hpp"
#include <iostream>

int main() {
    
    std::string s{"abcbcbcabb"};
    
    Solution3 test;
    
    std::cout << test.lengthOfLongestSubstring(s) << std::endl;
    
    return 0;
}
