#ifndef TreeNode_hpp
#define TreeNode_hpp

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val): val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode *left, TreeNode *right)
    : val(val), left(left), right(right) {}
};


#endif /* TreeNode_hpp */
