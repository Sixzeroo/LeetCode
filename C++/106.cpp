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
    TreeNode* solute(vector<int> &inorder, int il, int ir, vector<int> &postorder, int pl, int pr)
    {
        // cout<<il<<" "<<ir<<" "<<pl<<" "<<pr<<endl;
        if(pl > pr) return NULL;
        TreeNode *root = new TreeNode(postorder[pr]);
        int pos = il;
        // 获取中间位置情况
        for(; pos <= ir; pos++)
            if(inorder[pos] == postorder[pr]) break;
        root->left = solute(inorder, il, pos -1, postorder, pl, pl + pos - il - 1);
        root->right = solute(inorder, pos + 1, ir, postorder, pl + pos - il, pr -1);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return solute(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
};