class Solution {
public:
    // dp 思想
    bool isScramble(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        int len = s1.size();
        vector<vector<vector<bool> > > dp(len, vector<vector<bool> >(len, vector<bool>(len+1, false)));
        for(int i = 0; i < len; i++)
            for(int j = 0; j < len; j++)
            {
                dp[i][j][1] = (s1[i] == s2[j]);
            }
        // dp[i][j][k] 表示s1从i位开始 s2从j位开始的k位长的字符串是Scramble的
        for(int len2 = 2; len2 <= len; len2++)
            for(int i = 0; i < len - len2 + 1; i++)
                for(int j = 0; j < len - len2 + 1; j++)
                    for(int k = 1; k < len2; k++)
                    {
                        // 递推公式
                        // 原串分割成两个串，两种情况是可以证明是Scramble的
                        if((dp[i][j][k] && dp[i+k][j+k][len2-k]) || (dp[i][j+len2-k][k] && dp[i+k][j][len2-k]))
                        {
                            dp[i][j][len2] = true;
                            break;
                        }
                    }
        return dp[0][0][len];
    }
};