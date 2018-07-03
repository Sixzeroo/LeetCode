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
    TreeNode *createNode(int val){
        TreeNode *node = new TreeNode(val);
        return node;
    }
    
    vector<TreeNode*> getTree(int left, int right, map<pair<int,int>,vector<TreeNode*>>& dp){
        if(left > right || left < 1)
            return {nullptr};

        if(left == right)
            return {createNode(left)};
        
        pair<int,int> p = make_pair(left,right);
        if(dp.find(p) != dp.end()){
            return dp[p];
        }
        
        vector<TreeNode*> lefts,rights,all;
        for(int i = left; i <= right;i++){
            lefts = getTree(left,i-1,dp);
            rights = getTree(i+1,right,dp);
            for(int j = 0;j < lefts.size();j++){
                for(int k = 0;k < rights.size();k++){
                    TreeNode* node = createNode(i);
                    node->left = lefts[j];
                    node->right = rights[k];
                    all.push_back(node);
                }
            }
        }
        
        return dp[p] = all;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        if(!n)
            return {};
        
        vector<int> nums;
        for(int i = 1;i <= n;i++)
            nums.push_back(i);

        map<pair<int,int>, vector<TreeNode*>> dp;
        return getTree(1,n,dp);
    }
};