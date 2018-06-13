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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL)
            return res;
        stack<TreeNode*> s;
        TreeNode* cur, *pre = NULL;
        s.push(root);
        while(!s.empty())
        {
            cur = s.top();
            // 没有孩子节点或者孩子节点都被访问过
            if((cur->left == NULL && cur->right == NULL) || 
              (pre != NULL && (pre == cur->left || pre == cur->right)))
            {
                res.push_back(cur->val);
                s.pop();
                pre = cur;
            }
            else
            {
                // 先放右边的再放左边的，使得先访问左边的节点再访问右边的节点
                if(cur->right != NULL)
                    s.push(cur->left);
                if(cur->left != NULL)
                    s.push(cur->right);
            }
        }
        return res;
    }
};