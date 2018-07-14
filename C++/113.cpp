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
    void solute(TreeNode* root, vector<vector<int> > &res, vector<int> local, int sum)
    {
        if(root->left == NULL && root->right == NULL)
        {
            local.push_back(root->val);
            if(sum == root->val) res.push_back(local);
            return;
        }
        if(root->left != NULL)
        {
            local.push_back(root->val);
            solute(root->left, res, local, sum - root->val);
            local.pop_back();
        }
        if(root->right != NULL)
        {
            local.push_back(root->val);
            solute(root->right, res, local, sum - root->val);
            local.pop_back();
        }
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > res;
        if(root == NULL) return res;
        vector<int> local;
        solute(root, res, local, sum);
        return res;
    }
};