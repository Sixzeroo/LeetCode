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
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode *p = root;
        stack<TreeNode*> st;
        vector<int> res;
        while(p!= NULL || !st.empty())
        {
            while(p!=NULL)
            {
                res.push_back(p->val);
                st.push(p);
                p = p->left;
            }
            if(!st.empty())
            {
                p = st.top();
                st.pop();
                p = p -> right;
            }
        }
        return res;
    }
};