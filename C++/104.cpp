/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void helper(TreeNode* root, int & maxv, int h)
    {
        maxv = max(maxv, h);
        if(root->left != NULL) helper(root->left, maxv, h+1);
        if(root->right != NULL) helper(root->right, maxv, h+1);
    }
    
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int res = 0;
        helper(root, res, 1);
        return res;
    }
};