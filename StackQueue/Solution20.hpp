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
        
        std::stack<char> s_stack;
        
        for (char c: s) {
            if (c == '[' || c == '(' || c == '{') {
                s_stack.push(c);
            } else {
                switch (c) {
                    case ']':
                        if (!s_stack.empty() && s_stack.top() == '[' ) {
                            s_stack.pop();
                        } else {
                            return false;
                        }
                        break;
                    case ')':
                        if (!s_stack.empty() && s_stack.top() == '(') {
                            s_stack.pop();
                        } else {
                            return false;
                        }
                        break;
                    case '}':
                        if (!s_stack.empty() && s_stack.top() == '{') {
                            s_stack.pop();
                        } else {
                            return false;
                        }
                        break;
                    default:
                        break;
                }
            }
        }
        
        return (s_stack.empty() ? true : false);
    }
    
};

#endif /* Solution20_hpp */
