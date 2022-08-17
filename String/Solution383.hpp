#ifndef Solution383_hpp
#define Solution383_hpp

// Problem 383: Ransom Note
#include <string>
#include <vector>
#include <unordered_map>

using std::string, std::vector, std::unordered_map;

class Solution383 {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> magazine_count(128);
        
        for (int i = 0; i < magazine.size(); ++i) {
            int letter = (int) magazine[i];
            magazine_count[letter]++;
        }
        
        for (int i = 0; i < ransomNote.size(); ++i) {
            int letter = (int) ransomNote[i];
            if (magazine_count[letter] > 0) {
                magazine_count[letter]--;
            } else {
                return false;
            }
        }
        
        return true;
    }
};


#endif /* Solution383_hpp */
