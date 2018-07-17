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
    void solute(TreeNode* root, int &res, int local)
    {
        local = local*10 + root->val;
        if(root->left == NULL && root->right == NULL) {
            res += local;
            return;
        }
        if(root->left != NULL) solute(root->left, res, local);
        if(root->right != NULL) solute(root->right, res, local);
    }
    
    int sumNumbers(TreeNode* root) {
        int res = 0;
        if(root == NULL) return res;
        solute(root, res, 0);
        return res;
    }
};