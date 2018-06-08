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
    // 获得中序遍历序列
    void inorder(TreeNode *root, deque<int> &d)
    {
        if(root == NULL)
            return ;
        inorder(root->left, d);
        d.push_back(root->val);
        inorder(root->right, d);
    }
    
    // 将排序好以后的中序遍历序列重新写回BST中
    void convert(TreeNode *root, deque<int> &d)
    {
        if(root == NULL)
            return;
        convert(root->left, d);
        root->val = d.front();
        d.pop_front();
        convert(root->right, d);
    }
    
    void recoverTree(TreeNode* root) {
        deque<int> d;
        inorder(root, d);
        // 对中序遍历序列进行排序
        sort(d.begin(), d.end());
        convert(root, d);
    }
};