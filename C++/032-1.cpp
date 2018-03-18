class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.length(), res = 0;
        // len+1 数组，最前面一个当做0
        vector<int> dp(len+1, 0);
        for(int i=1; i<=len; i++)
        {
            if(i>1 && s[i-1] == ')' && s[i-2] == '(') dp[i]=dp[i-2] + 2;
            if(i>1 && s[i-1] == ')' && s[i-2] == ')' && s[i-dp[i-1]-2] == '(') dp[i] = dp[i-1] + dp[i-dp[i-1]-2] + 2;
            res = max(res, dp[i]);
        }
        return res;
    }
};