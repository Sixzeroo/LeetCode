class Solution {
public:
    // 回溯法
    void backtracking(int n, int k, vector<vector<int> > &res, int cnt, vector<int> local)
    {
        if(local.size() == k)
        {
            res.push_back(local);
            return;
        }
        if(cnt == n + 1)
            return;
        backtracking(n, k, res, cnt+1, local);
        local.push_back(cnt);
        backtracking(n, k, res, cnt+1, local);
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > res;
        vector<int> local;
        backtracking(n, k, res, 1, local);
        return res;
    }
};