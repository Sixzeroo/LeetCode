/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 递归解法
class Solution {
public:
    TreeNode* solute(vector<int>& preorder, int pl, int pr, vector<int> &inorder, int il, int ir)
    {
        if(pl > pr) return NULL;
        TreeNode *root = new TreeNode(preorder[pl]);
        int pos = il;
        for(; pos <= ir; pos ++)
            if(inorder[pos] == preorder[pl]) break;
        root->left = solute(preorder, pl + 1, pl + pos - il, inorder, il, pos - 1);
        root->right = solute(preorder, pl + pos - il + 1, pr, inorder, pos + 1, ir);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return solute(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};