class Solution {
public:
    // dp 方程求解 dp[i][j] 表示s[0-i]的子序列和t[0-j]相等的情况
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<int> dp(m+1, 0);
        dp[0] = 1;
        for(int i = 0; i < n; i++)
            for(int j = m-1; j >= 0; j--)
            {
                // 找到相同的字母，则加上前面对应的方案数
                if(s[i] == t[j])
                    dp[j + 1] += dp[j];
            }
        return dp[m];
    }
};