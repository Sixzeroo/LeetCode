class Solution {
public:
    // dp思路
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size();
        if(n + m != s3.size()) return false;
        vector<bool> dp(n+1, false);
        // dp[i][j] 表示s1的前i位和s2的前j位能否组合成s3的前i+j位
        dp[0] = true;
        for(int i = 0; i < n; i++)
        {
            dp[i + 1] = dp[i] && s1[i] == s3[i];
        }
        for(int i = 0; i < m; i++)
        {
            dp[0] = dp[0] && s2[i] == s3[i];
            for(int j = 0; j < n; j++)
            {
                // 状态转移方程，s1 或者 s2任意两个的当前字符加入到s3中
                dp[j+1] = (dp[j+1] && s2[i] == s3[i+j+1]) || (dp[j] && s1[j] == s3[i+j+1]);
            }
        }
        return dp[n];
    }
};