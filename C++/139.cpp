class Solution {
public:
    // dp 思路 dp[i] 表示从0-i位是否能够拆分
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.size();
        if(len == 0) return false;
        vector<bool> dp(len + 1, false);
        dp[0] = true;
        for(int i = 1; i <= len; i++)
            for(int j = i-1; j >= 0; j--)
            {
                if(dp[j] && find(wordDict.begin(), wordDict.end(), s.substr(j, i-j)) != wordDict.end())
                {
                    dp[i] = true;
                    break;
                }
            }
        return dp[len];
    }
};