class Solution {
public:
    // 使用回溯法
    void backtracking(vector<vector<int> > &res, vector<int>& candidates, vector<int> local, int sum, int target)
    {
        if(sum > target) return;
        else if(sum == target) res.push_back(local);
        else
        {
            int len = candidates.size();
            for(int i=0; i<len; i++)
            {
                // 排除重复数组，每次加入的至少不小于上次加入的
                if(!local.empty() && candidates[i] < local.back()) continue;
                local.push_back(candidates[i]);
                sum += candidates[i];
                backtracking(res, candidates, local, sum, target);
                local.pop_back();
                sum -= candidates[i];
            }
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        vector<int> local;
        backtracking(res, candidates, local, 0, target);
        return res;
    }
};