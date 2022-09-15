#ifndef Solution567_hpp
#define Solution567_hpp

// Problem 567: Permutation in String
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

class Solution567 {
public:
    // using hashmap
    bool checkInclusion(std::string s1, std::string s2) {
        if (s1.size() > s2.size())
            return false;
        
        std::unordered_map<int, int> map1;
        std::unordered_map<int, int> map2;
        
        for (int i = 0; i < s1.size(); ++i) {
            map1[s1[i] - 'a'] += 1;
            map2[s2[i] - 'a'] += 1;
        }
        
        int matches = 0;
        for (int i = 0; i < 26; ++i) {
            if (map1[i] == map2[i]) {
                ++matches;
            }
        }
        
        int left = 0;
        int right = s1.size();
        int idx;
    }
    
    // using vectors - not complete
    bool checkInclusionIP(std::string s1, std::string s2) {
        if (s1.size() > s2.size())
            return false;
        
        std::vector<int> s1_count(26), s2_count(26);
        for (int i = 0; i < s1.size(); ++i) {
            s1_count[s1[i] - 'a'] += 1; // use ASCII values to determine index
            s2_count[s2[i] - 'a'] += 1;
        }
        
        int matches = 0;
        for (int i = 0; i < 26; ++i) {
            if (s1_count[i] == s2_count[i]) {
                ++matches;
            }
        }
        
        
        int left = 0;
        int right = s1.size(); // we're moving our window by 1
        int idx;
        
        while (right < s2.size()) {
            if (matches == 26) // we found our permutation
                return true;
            
            // test right end of window - char added to window
            idx = s2[right] - 'a';
            s2_count[idx] += 1;
            // two scenarios - we either are a match now
            // or used to be and now we're not
            if (s1_count[idx] == s2_count[idx]) {
                ++matches;
            } else if (s1_count[idx] + 1 == s2_count[idx]) {
                --matches;
            }
            
            // repeat for left - the character leaving the window
            idx = s2[left] - 'a';
            s2_count[idx] -= 1;
            if (s1_count[idx] == s2_count[idx]) {
                ++matches;
            } else if (s1_count[idx] + 1 == s2_count[idx]) {
                --matches;
            }
            
            ++left;
            ++right;
        }
        
        // final check on left pointer
        idx = s2[left] - 'a';
        
        if (s1_count[idx] == s2_count[idx] && matches < 26) {
            ++matches;
        }
        
        // final check for matches
        return (matches == 26 ? true : false);
    }
};

#endif
