/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void func(TreeNode* node, vector<int> &v){
        if(node == NULL) return;

        func(node->left,v);
        v.push_back(node->val);
        func(node->right,v);
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> inorder;
        func(root, inorder);
        return inorder[k-1];
    }
};
