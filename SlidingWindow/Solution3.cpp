// Problem 3: Longest Substring Without Repeating Characters
#include <string>
#include <unordered_map>
#include <algorithm>

using std::string, std::unordered_map;

class Solution3 {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> char_map;
        int max_str = 0;
        int left = 0;
        int right = 0;
        
        while (right != s.size()) {
            char r_char = s[right];
            char_map[r_char]++;
            
            // once left and right pointers have the same char
            // shorten our window b/e left and right
            while (char_map[r_char] > 1) {
                char l_char = s[left];
                ++left;
                char_map[l_char]--;
            }

            max_str = std::max(max_str, (right - left) + 1);
            ++right;
        }
        
        return max_str;
    }
};
