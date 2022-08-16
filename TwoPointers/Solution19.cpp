// Problem 19: Remove Nth Node from End of List
#include "ListNode.hpp"

class Solution19 {
public:
    // first solution - sloppy
    ListNode* removeNthFromEnd1(ListNode *head, int n) {
        if (head->next == nullptr || head == nullptr) {
            return nullptr;
        }
        
        int count = 0;
        ListNode *cur = head;
        
        while (cur != nullptr) {
            ++count;
            cur = cur->next;
        }
        
        
        int prev_idx = count - n;
        count = 0;
        ListNode *prev = head;
        
        if (prev_idx - count == 0) {
            return prev->next;
        }
        
        while (count < prev_idx - 1) {
            ++count;
            prev = prev->next;
        }
        
        
        prev->next = prev->next->next;
        
        return head;
    }
    
    // much better to do a single pass using the nth int as a gap
    ListNode* removeNthFromEnd(ListNode *head, int n) {
        // need to have a ptr BEFORE head in case the node we're deleting is the first one
        ListNode *copy = new ListNode(0);
        copy->next = head;
        ListNode *first = copy;
        ListNode *second = copy;
        
        for (int i = 0; i <= n; ++i) {
            first = first->next;
        }
        
        // there's now a gap between first and second pointers
        // when first is null, second will be at node BEFORE
        // our target
        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }
        
        second->next = second->next->next;
        
        return copy->next;
    }
};
