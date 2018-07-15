/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
// 层次遍历
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL) return;
        vector<TreeLinkNode*> que;
        que.push_back(root);
        while(!que.empty())
        {
            vector<TreeLinkNode*> tem;
            for(int i = 0; i < que.size(); i++)
            {
                que[i]->next = i < que.size() - 1 ? que[i+1] : NULL;
                if(que[i]->left != NULL) tem.push_back(que[i]->left);
                if(que[i]->right != NULL) tem.push_back(que[i]->right);
            }
            que = tem;
        }
    }
};