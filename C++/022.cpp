class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtracking(res, n, 0, 0, "");
        return res;
    }
    
    // 回溯法实现
    void backtracking(vector<string> &res, int num, int index, int leftindex, string local)
    {
        // 退出条件
        if(2*num == index)
        {
            res.push_back(local);
            return;
        }
        // 左括号个数小于给定值
        if(leftindex < num)
        {
            local.push_back('(');
            backtracking(res, num, index+1, leftindex+1, local);
            local.pop_back();
        }
        // 右括号个数小于左括号个数
        if(index-leftindex < leftindex)
        {
            local.push_back(')');
            backtracking(res, num, index+1, leftindex, local);
            local.pop_back();
        }
    }
};