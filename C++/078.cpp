class Solution {
public:
    // 回溯法
    void backtracking(vector<int> &nums, vector<vector<int> > &res, int cnt, vector<int> local)
    {
        int len = nums.size();
        if(cnt == len)
        {
            res.push_back(local);
            return;
        }
        backtracking(nums, res, cnt+1, local);
        local.push_back(nums[cnt]);
        backtracking(nums, res, cnt+1, local);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> local;
        backtracking(nums, res, 0, local);
        return res;
    }
};