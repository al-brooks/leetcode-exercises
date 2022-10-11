#ifndef ListNode_hpp
#define ListNode_hpp
#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val{x}, next{nullptr} {}
    ListNode(int x, ListNode *next) : val{x}, next{next} {}
};

void insertAtHead(ListNode*& head, int val) {
    ListNode* new_node = new ListNode(val, head);
    head = new_node;
    return;
}

void createFromVector(ListNode*& head, std::vector<int>& vec) {
    for (int i = (int) vec.size() - 1; i > -1; --i) {
        insertAtHead(head, vec[i]);
    }
    return;
}

void printList(ListNode *head) {
    ListNode *curr = head;
    
    while (curr != nullptr) {
        std::cout << "[" << curr->val << "] --> ";
        curr = curr->next;
    }
    
    std::cout << "[nullptr]\n" << std::endl;
    return;
}

#endif /* ListNode_hpp */
