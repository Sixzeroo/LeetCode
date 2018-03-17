class Solution {
public:
    // 使用回溯法
    void backtracking(vector<vector<int> > &res, vector<int>& candidates, vector<int> local, int sum, int target, int *used)
    {
        if(sum > target) return;
        else if(sum == target) res.push_back(local);
        else
        {
            int len = candidates.size();
            for(int i=0; i<len; i++)
            {
                // 判断是否有被用过
                if(used[i]) continue;
                // 排除重复数组，每次加入的至少不小于上次加入的
                if(!local.empty() && candidates[i] < local.back()) continue;
                local.push_back(candidates[i]);
                sum += candidates[i];
                used[i] = 1;
                backtracking(res, candidates, local, sum, target, used);
                used[i] = 0;
                local.pop_back();
                sum -= candidates[i];
                // 相同元素只考虑一次
                while(i<len-1 && candidates[i] == candidates[i+1]) i++;
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // 排序方便后面判断
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > res;
        vector<int> local;
        int used[candidates.size()];
        memset(used, 0, sizeof(used));
        backtracking(res, candidates, local, 0, target, used);
        return res;
    }
};