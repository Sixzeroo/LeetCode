class Solution {
public:
    // 回溯法求解，求不同数字的排列数量
    void backtracking(int &res, int cur, int n,vector<int> local)
    {
        if(cur > 10) return;
        if(cur == n)
        {
            res++;
            return;
        }
        else if(cur>0) res++;
        for(int i=0; i<10; i++)
        {
            if(cur == 1 && i==0) continue;
            if(local[i] != 1)
            {
                local[i] = 1;
                backtracking(res, cur+1, n, local);
                local[i] = 0;
            }
        }
    }
    
    int countNumbersWithUniqueDigits(int n) {
        vector<int> local(10, 0);
        int res = 0;
        backtracking(res, 0, n, local);
        return res;
    }
};