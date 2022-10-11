#ifndef Solution83_hpp
#define Solution83_hpp

#include "ListNode.hpp"

class Solution83 {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        
        ListNode* current = head;
        
        while (current != nullptr && current->next != nullptr) {
            if (current->val == current->next->val) {
                current->next = current->next->next;
            } else {
                current = current->next;
            }
        }
        
        return head;
    }
};

#endif /* Solution83_hpp */
