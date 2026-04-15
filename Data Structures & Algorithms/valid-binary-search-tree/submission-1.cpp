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
    bool check(TreeNode* node, int mini, int maxi){
        if(node == NULL) return true;
        if(node-> val <= mini || node->val >= maxi) return false;

        bool left = check(node->left, mini, node->val);
        bool right = check(node->right, node->val, maxi);

        return left & right;
    }
    bool isValidBST(TreeNode* root) {
        bool ans = check(root, -1e9, 1e9);
        return ans;
    }
};
