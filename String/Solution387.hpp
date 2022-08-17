#ifndef Solution387_hpp
#define Solution387_hpp

// Problem 387: First Unique Character in a String
#include <string>
#include <unordered_map>
#include <vector>

using std::string, std::unordered_map, std::vector;

class Solution387 {
public:
    int firstUniqChar1(string s) {
        unordered_map<char, int> chars;
        
        for (int i = 0; i < s.size(); ++i) {
            if (chars.find(s[i]) == chars.end()) {
                chars[s[i]] = 1;
            } else {
                chars[s[i]]++;
            }
        }
        
        for (int i = 0; i < s.size(); ++i) {
            if (chars[s[i]] == 1)
                return i;
        }
        
        return -1;
    }
    
    // can use character int vals to store counts
    int firstUniqChar2(string s) {
        vector<int> count(128); // 128 ASCII vals for alphabet - lowercase is 97 - 122
        // vector index = char val
        
        for (int i = 0; i < s.size(); ++i)
            count[s[i]]++;
        
        for (int i = 0; i < s.size(); ++i) {
            if (count[s[i]] == 1)
                return i;
        }
        
        return -1;
    }
};


#endif /* Solution387_hpp */
