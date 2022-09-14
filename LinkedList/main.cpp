#include "ListNode.hpp"

int main() {
    ListNode *test{nullptr};
    
    insertAtHead(test, 14);
    insertAtHead(test, 23);
    printList(test);
    
    delete test;
    
    return 0;
}
