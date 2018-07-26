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
    void helper(vector<int> &l, TreeNode* root)
    {
        if(root->left != NULL) helper(l, root->left);
        l.push_back(root->val);
        if(root->right != NULL) helper(l, root->right);
    }
    
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL) return false;
        vector<int> sort_list;
        helper(sort_list, root);
        int len = sort_list.size();
        int f = 0, s = len - 1;
        while(f < s)
        {
            if(sort_list[f] + sort_list[s] == k) return true;
            else if (sort_list[f] + sort_list[s] > k) s--;
            else f++;
        }
        return false;
    }
};