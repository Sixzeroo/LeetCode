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
    bool solute(TreeNode* root, int &h) {
        if(root == NULL) {
            h = 0;
            return true;
        }
        int hl, hr;
        bool res = solute(root->left, hl) && solute(root->right, hr);
        h = max(hl, hr) + 1;
        return res ? abs(hl - hr) < 2 : false;
    }
    
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        int h;
        return solute(root, h);
    }
};