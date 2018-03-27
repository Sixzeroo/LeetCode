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
    // 栈实现二叉树中序遍历
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* p=root;
        vector<int> res;
        while(p!=NULL || !st.empty())
        {
            while(p)
            {
                st.push(p);
                p = p->left;
            }
            p = st.top();
            st.pop();
            res.push_back(p->val);
            p = p->right;
        }
        return res;
    }
};