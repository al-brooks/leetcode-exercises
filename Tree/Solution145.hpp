#ifndef Solution145_hpp
#define Solution145_hpp

// Problem 145: Binary Tree Postorder Traversal
// Traversal - Left, Right, Root
#include "TreeNode.hpp"
#include <vector>
#include <stack>

using std::vector, std::stack;

class Solution145 {
private:
    vector<int> nodes;
public:
    // Method 1: Using Recursion
    vector<int> postorderTraversalRecursion(TreeNode *root) {
        if (root == nullptr)
            return nodes;
        
        postorderTraversalRecursion(root->left);
        postorderTraversalRecursion(root->right);
        nodes.push_back(root->val);
        return nodes;
    }
    
    // Method 2: Using Iteration w/ Stack
    vector<int> postorderTraversalIteration(TreeNode *root) {
        stack<TreeNode*> node_stack;
        TreeNode *curr = root;
        TreeNode *prev = nullptr;
        
        while (curr != nullptr || !node_stack.empty()) {
            // stack up left nodes
            if (curr != nullptr) {
                node_stack.push(curr);
                curr = curr->left;
            } else {
                // once you're at leftmost node
                TreeNode *node = node_stack.top();
                
                // If you're a leaft node - add to vector, else move to right subtree
                if (node->right != nullptr && node->right != prev) {
                    curr = node->right;
                } else {
                    nodes.push_back(node->val);
                    prev = node;
                    node_stack.pop();
                }
            }
        }
        
        return nodes;
    }
};


#endif /* Solution145_hpp */
