class Solution {
public:
    // 回溯法
    void backtracking(vector<vector<int> > &res, vector<int> &nums, vector<int> local, vector<bool> &used)
    {
        int len = nums.size();
        if(local.size() == len) 
        {
            res.push_back(local);
            return;
        }
        for(int i=0; i<len; i++)
        {
            if(!used[i])
            {
                used[i] = true;
                local.push_back(nums[i]);
                backtracking(res, nums, local, used);
                local.pop_back();
                used[i] =false;
                // 去除重复部分
                while(i+1 < len && nums[i+1] == nums[i]) i++;
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> local;
        vector<bool> used(nums.size(), false);
        // 先进行排序
        sort(nums.begin(), nums.end());
        backtracking(res, nums, local, used);
        return res;
    }
};