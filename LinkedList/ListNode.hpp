#ifndef ListNode_hpp
#define ListNode_hpp

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val{x}, next{nullptr} {}
};

#endif /* ListNode_hpp */
