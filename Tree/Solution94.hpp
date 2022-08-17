#ifndef Solution94_hpp
#define Solution94_hpp

// Problem 94: Binary Tree Inorder Traversal
// Inorder Traversal: Left, Root, Right
#include "TreeNode.hpp"
#include <vector>
#include <stack>

using std::vector, std::stack;

class Solution94 {
private:
    vector<int> nodes;
public:
    // Method 1: Recursion
    vector<int> inorderTraversalRecursion(TreeNode *root) {
        if (root == nullptr)
            return nodes;
        
        inorderTraversalRecursion(root->left);
        nodes.push_back(root->val);
        inorderTraversalRecursion(root->right);
        
        return nodes;
    }
    
    // Method 2: Using Iteration w/ Stack
    vector<int> inorderTraversalIterative(TreeNode *root) {
        stack<TreeNode*> node_stack;
        TreeNode *curr = root;
        
        while (curr != nullptr || !node_stack.empty()) {
            while (curr != nullptr) {
                node_stack.push(curr);
                curr = curr->left;
            }
            curr = node_stack.top();
            node_stack.pop();
            nodes.push_back(curr->val);
            curr = curr->right;
        }
        
        return nodes;
    }
    
};


#endif /* Solution94_hpp */
