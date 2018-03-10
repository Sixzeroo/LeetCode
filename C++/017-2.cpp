class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.size() == 0) return res;
        string local;
        vector<string> table(2, "");
        table.push_back("abc");
        table.push_back("def");
        table.push_back("ghi");
        table.push_back("jkl");
        table.push_back("mno");
        table.push_back("pqrs");
        table.push_back("tuv");
        table.push_back("wxyz");
        // 使用回溯法
        backtracking(table, res, local, 0, digits);
        
        return res;
    }
    
    // 关键之一，res为引用，方便后面加值
    void backtracking(const vector<string> &table, vector<string> &res, string local, int index, string digits)
    {
        // 到达枚举的终点，要将东西加入到 结果中去
        if(index == digits.size())
            res.push_back(local);
        for(int i=0;i<table[digits[index] - '0'].size();++i)
        {
            local.push_back(table[digits[index] - '0'][i]);
            // 不断进行尝试
            backtracking(table, res, local, index+1, digits);
            // 尝试以后要删除
            local.pop_back();
        }
    }
};