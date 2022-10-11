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
            ListNode* temp = current->next;
            while (current->val == temp->val) {
                current->next = temp->next;
                if (current->next == nullptr) {
                    break;
                } else {
                    temp = current->next;
                }
            }
            
            current = current->next;
        }
        
        return head;
    }
};

#endif /* Solution83_hpp */
