/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 递归方案
class Solution {
public:
    // 递归实现，返回链表中最后一个节点的指针
    TreeNode* solute(TreeNode* root)
    {
        if(root == NULL) return NULL;
        if(root->left == NULL && root->right == NULL) return root;
        TreeNode* left = solute(root->left);
        TreeNode* right = solute(root->right);
        if(left == NULL) return right;
        if(right == NULL) {
            root->right = root->left;
            root->left = NULL;
            return left;
        }
        left->right = root->right;
        root->right = root->left;
        root->left = NULL;
        return right;
    }
    
    void flatten(TreeNode* root) {
        solute(root);
    }
};