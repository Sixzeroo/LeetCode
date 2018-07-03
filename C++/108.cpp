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
    TreeNode* helper(const vector<int> &nums, int l, int r)
    {
        if(l > r) 
            return NULL;
        int m = (l + r)/2;
        TreeNode* root = new TreeNode(nums[m]);
        root->left = helper(nums, l, m-1);
        root->right = helper(nums, m+1, r);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return NULL;
        TreeNode* root = helper(nums, 0, len-1);
        return root;
    }
};