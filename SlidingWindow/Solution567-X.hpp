#ifndef Solution567_hpp
#define Solution567_hpp

// Problem 567: Permutation in String
#include <string>
#include <vector>

class Solution567 {
public:
    bool checkInclusion(string s1, string s2) {
        std::vector<int> char_count(128);
        
        for (int i = 0; i < s1.size(); ++i) {
            char_count[s1[i]]++;
        }
        
        for (int i = 0; i < s2.size(); ++i) {
            if (char_count[s2[i]] > 0) {
                int right = i;
                int count = 0;
                int len = s1.size();
                while (char_count[s1[right]] > 0) {
                    ++count;
                    char_count[s2[right]]--;
                    ++right;
                }
                return (count == s1.size());
            }
        }
        
        return false;
    }
};

#endif
