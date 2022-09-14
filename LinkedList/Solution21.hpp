// Problem 21: Merge Two Sorted Lists

#ifndef Solution21_hpp
#define Solution21_hpp

#include "ListNode.hpp"

class Solution21 {
public:
    // Recursive Approach
    // O(n + m) Time Complexity
    // O(n + m) Space Complexity
    ListNode* mergeTwoListsRecursive(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) {
            return list2;
        } else if (list2 == nullptr) {
            return list1;
        } else if (list1->val <= list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoLists(list2->next, list1);
            return list2;
        }
    }
    
    // Iterative Approach
    // O(n + m) Time Complexity
    // O(1) Space Complexity
    ListNode* mergeTwoListsIterative(ListNode* list1, ListNode* list2) {
        ListNode* merged = new ListNode(-1);
        ListNode* new_head = merged;
        
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                merged->next = list1;
                list1 = list1->next;
            } else {
                merged->next = list2;
                list2 = list2->next;
            }
            merged = merged->next;
        }
        
        // If one list is shorter than the other move
        // all remaining values to the new list
        merged->next = (list1 == nullptr) ? list2 : list1;
        
        return new_head->next;
        
        
    }
};

#endif /* Solution21_hpp */
