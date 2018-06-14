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
    int res;
    
    int maxPathSum(TreeNode* root) {
        res = INT_MIN;
        traverse(root);
        return res;
    }
    
    int traverse(TreeNode* root) {
        if(root == NULL) return 0;
        int l = max(0, traverse(root->left));
        int r = max(0, traverse(root->right));
        // 全局的最值进行更新
        res = max(res, l + r + root->val);
        // 贪心思想，放弃小于0的东西
        return max(0, max(l, r) + root->val);
    }
};