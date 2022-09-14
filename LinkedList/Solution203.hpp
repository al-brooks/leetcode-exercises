#ifndef Solution203_hpp
#define Solution203_hpp

#include "ListNode.hpp"

class Solution203 {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* current = head;
        
        // in case val is at beginning of list
        while (current != nullptr && current->val == val) {
            current = current->next;
        }
        
        ListNode *new_head = current;
        ListNode *prev = nullptr;
        
        while (current != nullptr) {
            if (current->val != val) {
                prev = current;
                current = current->next;
            } else {
                current = current->next;
                prev->next = current;
            }
        }
        
        return new_head;
    }
};

#endif /* Solution203_hpp */
