#ifndef Solution144_hpp
#define Solution144_hpp

// Problem 144: Binary Tree Preorder Traversal
// Preorder Traversal - Root, Left, Right
#include "TreeNode.hpp"
#include <vector>
#include <stack>

using std::vector, std::stack;

class Solution144 {
private:
    vector<int> nodes;
public:
    vector<int> preorderTraversalRecursive(TreeNode *root) {
        if (root == nullptr) {
            return nodes;
        }
        
        nodes.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return nodes;
    }
    
    vector<int> preorderTraversalIterative(TreeNode *root) {
        stack<TreeNode*> node_vals;
        TreeNode *curr = root;
        while (curr != nullptr || !node_vals.empty()) {
            if (curr != nullptr) {
                nodes.push_back(curr->val);
                if (curr->right) {
                    node_vals.push(curr->right);
                }
                curr = curr->left;
            } else {
                curr = node_vals.top();
                node_vals.pop();
            }
        }
        return nodes;
    }
};


#endif /* Solution144_hpp */
