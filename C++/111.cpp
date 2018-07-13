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
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        vector<TreeNode*> que;
        if(root->left != NULL) que.push_back(root->left);
        if(root->right != NULL) que.push_back(root->right);
        if(que.empty()) return 1;
        int res = 2;
        while(!que.empty())
        {
            vector<TreeNode*> tem;
            for(auto it : que)
            {
                if(it->left == NULL && it->right == NULL) return res ;
                if(it->left != NULL) tem.push_back(it->left);
                if(it->right != NULL) tem.push_back(it->right);
            }
            res ++;
            que = tem;
        }
        return res;
    }
};