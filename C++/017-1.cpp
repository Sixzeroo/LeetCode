class Solution {
public:
    // 为intput数组添加dig中的字母
    vector<string> addDig(int dig, vector<string> input)
    {
        vector<string> res;
        // 特殊情况
        if(dig == 0 || dig == 1)
            return res;
        vector<string> arr = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        // 一开始要在里面添加一个空字符串
        if(input.size() == 0)
            input.push_back("");
        for(int i=0;i<input.size();++i)
        {
            for(int j=0;j<arr[dig-2].length();++j)
            {
                res.push_back(input[i]+arr[dig-2][j]);
            }
        }
        return res;
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        for(int i=0;i<digits.length();++i)
        {
            res = addDig(digits[i]-'0', res);
            if(res.size() == 0)
                return res;
        }
        return res;
    }
};