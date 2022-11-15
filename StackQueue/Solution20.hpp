#ifndef Solution20_hpp
#define Solution20_hpp

#include <iostream>
#include <string>
#include <unordered_map>
#include <stack>

class Solution20 {
public:
    bool isValid(std::string s) {
        if (s.size() % 2 == 1)
            return false;
        
        std::unordered_map<char, int> chars {
            {'(', -1},
            {'[', -2},
            {'{', -3},
            {')', 1},
            {']', 2},
            {'}', 3},
        };
        std::stack<char> s_stack;
        
        for (char symbol: s) {
            if (chars[symbol] < 0) {
                // open bracket
                s_stack.push(symbol);
            } else {
                // closing bracket
                if (!s_stack.empty()) {
                    char val = s_stack.top();
                    s_stack.pop();
                    
                    if (chars[val] + chars[symbol] != 0)
                        return false;
                } else {
                    return false;
                }
            }
        }
        
        if (!s_stack.empty())
            return false;
        
        return true;
        
    }
    
};

#endif /* Solution20_hpp */
