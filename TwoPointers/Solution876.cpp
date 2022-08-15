// Problem 876: Middle of the Linked List
#include "ListNode.hpp"
#include <vector>

using std::vector;

class Solution876 {
public:
    ListNode* middleNode1(ListNode *head) {
        ListNode *start = head;
        ListNode *end = head;
        int count = 0;
        
        while (end != nullptr) {
            end = end->next;
            ++count;
        }
        
        int mid = count / 2;
        count = 0;
        
        while (count < mid) {
            start = start->next;
            ++count;
        }
        
        return start;
    }
    
    // using a vector to push all nodes into and access middle index
    ListNode* middleNode2(ListNode *head) {
        vector<ListNode*> nodes;
        
        ListNode *curr = head;
        while (curr != nullptr) {
            nodes.push_back(curr);
            curr = curr->next;
        }
        
        int end_idx = nodes.size();
        return nodes[end_idx / 2];
    }
    
    
    // using a fast and slow pointer where fast is 2x faster than slow - slow will be
    // in the middle by the time fast is a nullptr
    ListNode* middleNode3(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        return slow;
    }
};
