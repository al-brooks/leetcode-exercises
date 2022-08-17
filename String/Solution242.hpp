#ifndef Solution242_hpp
#define Solution242_hpp

// Problem 242: Valid Anagram
#include <string>
#include <unordered_map>

using std::string, std::unordered_map;

class Solution242 {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        
        unordered_map<char, int> char_count;
        
        for (int i = 0; i < s.size(); ++i) {
            if (char_count.find(s[i]) != char_count.end()) {
                char_count[s[i]]++;
            } else {
                char_count[s[i]] = 1;
            }
        }
        
        for (int i = 0; i < t.size(); ++i) {
            if (char_count[t[i]] > 0) {
                char_count[t[i]]--;
            } else {
                return false;
            }
        }
        
        return true;
    }
};


#endif /* Solution242_hpp */
