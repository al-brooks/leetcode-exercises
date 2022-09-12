#ifndef Solution141_hpp
#define Solution141_hpp

#include "ListNode.hpp"
#include <unordered_map>

class Solution141 {
public:
    // hash table
    bool hasCycle(ListNode *head) {
        std::unordered_map<ListNode*, bool> map;
        
        while (head != nullptr) {
            if (map[head]) {
                return true;
            } else {
                map[head] = true;
                head = head->next;
            }
        }
        
        return false;
    }
    
    // turtle vs hare
    bool hasCycle2(ListNode *head) {
        if (head == nullptr) {
            return false;
        }
        
        ListNode *fast = head->next;
        ListNode *slow = head;
        
        while (fast != slow) {
            if (fast == nullptr || fast->next == nullptr) {
                return false;
            }
            fast = fast->next->next;
            slow = slow->next;
        }
        
        return true;
    }
};

#endif /* Solution141_hpp */
