class Solution {
public:
    // 判断在row，col处放置是否可行
    bool isValid(vector<string> local, int row, int col, int n)
    {
        for(int i=0; i<row; i++)
        {
            if(local[i][col] == 'Q')
                return false;
        }
        for(int i=row-1,j=col-1; i>=0 && j>=0; i--,j--)
            if(local[i][j] == 'Q')
                return false;
        for(int i=row-1,j=col+1; i>=0 && j<n; i--,j++)
            if(local[i][j] == 'Q')
                return false;
        return true;
    }
    
    // 回溯法
    void backtracking(vector<vector<string> > &res, int cur, int n, vector<string> local)
    {
        if(cur ==n )
        {
            res.push_back(local);
            return;
        }
        for(int i=0; i<n; i++)
        {
            if(isValid(local, cur, i, n))
            {
                local[cur][i] = 'Q';
                backtracking(res, cur+1, n, local);
                local[cur][i] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> local(n, string(n, '.'));
        vector<vector<string> > res;
        backtracking(res, 0, n, local);
        return res;
    }
};