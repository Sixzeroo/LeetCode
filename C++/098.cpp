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
    bool helper(TreeNode *root, long long minv, long long maxv)
    {
        if(root == NULL) return true;
        
        if(root->val < minv || root->val > maxv) return false;
        
        if((root->left && root->val <= root->left->val) || (root->right && root->val >= root->right->val)) return false;
        
        return helper(root->left, minv, root->val - 1) && helper(root->right, root->val + 1, maxv);
    }
    
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        return helper(root, INT_MIN, INT_MAX);
    }
};