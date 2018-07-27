/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
stack<TreeNode*> bst;
public:
    BSTIterator(TreeNode *root) {
        if(root != nullptr)
            bst.push(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !bst.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *node = bst.top();bst.pop();
        int v = node->val;
        
        if(node->left != nullptr && node->left->val != -1){
            bst.push(node);
            bst.push(node->left);

            return next();
        }else{
            if(node->right != nullptr)
                bst.push(node->right);

            node->val = -1;
        }
        
        return v;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */