#ifndef Solution567_hpp
#define Solution567_hpp

// Problem: 557: Reverse Words in a String III
#include <vector>
#include <string>

using std::vector, std::string;

class Solution557 {
public:
    string reverseWords(string s) {
        int start = 0;
        int end = 0;
        int last_space = -1; // for initial non-space edge case

        for (int idx = 0; idx <= s.size(); ++idx) {
          if (std::isspace(s[idx]) || idx == s.size()) {
            start = last_space + 1;
            end = idx - 1;
            while (start < end) {
              int temp = s[end];
              s[end--] = s[start];
              s[start++] = temp;
            }
            last_space = idx;
          }
        }
        
        return s;
    }
};

#endif
