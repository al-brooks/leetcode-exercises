#include "ListNode.hpp"
#include "Solution83.hpp"

int main() {
    ListNode *head{nullptr};
    std::vector<int> nums {1, 1, 2};
    createFromVector(head, nums);
    printList(head);
    
//    Solution83 test83;
//    test83.deleteDuplicates(head);
//    printList(head);
        
    delete head;
    
    return 0;
}
