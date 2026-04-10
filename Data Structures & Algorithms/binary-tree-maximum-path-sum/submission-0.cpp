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
    int func(TreeNode* node, int &ans){
        if(node == NULL) return -1e9;

        int left = func(node->left, ans);
        int right = func(node->right, ans);
        if(left <= 0) left = 0;
        if(right <= 0) right = 0;
        int val = node->val + left + right;
        ans = max(ans, val);
        return max(node->val + left, node->val + right);
        
    }
    int maxPathSum(TreeNode* root) {
        int ans = -1e9;
        func(root, ans);
        return ans;
    }
};
