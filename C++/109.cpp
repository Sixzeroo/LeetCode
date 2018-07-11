/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    ListNode *node;
    
    // 利用递归的规律
    TreeNode* solute(int l, int r) {
        if(l > r) return NULL;
        int m = (l + r) / 2;
        TreeNode* left = solute(l, m - 1);
        TreeNode* root = new TreeNode(node->val);
        node = node->next;
        TreeNode* right = solute(m + 1, r);
        root->left = left;
        root->right = right;
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) return NULL;
        int len = 0;
        ListNode *tem = head;
        node = head;
        while(tem != NULL) 
        {
            tem = tem->next;
            len ++;
        }
        return solute(0, len-1);
    }
};