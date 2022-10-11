// Problem 206: Reverse Linked List
#ifndef Solution206_hpp
#define Solution206_hpp

#include "ListNode.hpp"

class Solution206 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* next = head;
        ListNode* prev {nullptr};
        
        while (next != nullptr) {
            next = next->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        
        return prev;
    }
};

#endif /* Solution206_hpp */
