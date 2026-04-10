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
    TreeNode* func(int preStart, int preEnd, int inStart, int inEnd, vector<int> &preorder, map<int, int> &mp){
        if(inStart > inEnd || preStart > preEnd) return NULL;
        
        int val = preorder[preStart];
        int index = mp[val];
        int countLeft = index - inStart;
        int countRight = inEnd - index;
        TreeNode* node = new TreeNode(val);

        TreeNode* leftNode = func(preStart+1, preEnd - countRight, inStart, index - 1, preorder, mp);
        TreeNode* rightNode = func(countLeft + preStart + 1, preEnd, index + 1, inEnd, preorder, mp);
        node->left = leftNode;
        node->right = rightNode;
        // int leftVal = leftNode == NULL ? -1 : leftNode->val;
        // int rightVal = rightNode == NULL ? -1 : rightNode->val;
        // cout << val << " " << leftVal << " " << rightVal << "\n";
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> mp;
        for(int i = 0; i < inorder.size(); i++) mp[inorder[i]] = i;

        TreeNode* root = func(0, preorder.size(), 0, inorder.size()-1, preorder, mp);
        return root;
    }
};
