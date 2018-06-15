class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        if(n == 0) return 0;
        // dp[i][j] 表示s[i...j]是不是一个回文串
        vector<vector<bool> > dp(n, vector<bool>(n, false));
        // cut[i] 表示s[i...n-1]的结果
        vector<int> cut(n);
        for(int i = n-1; i >= 0; i--)
        {
            cut[i] = n - i - 1;
            for(int j = i; j < n; j++)
            {
                // 判断当前是不是回文串
                if(s[i] == s[j] && (j - i < 2 || dp[i+1][j-1]))
                {
                    dp[i][j] = true;
                    if(j == n-1)
                        cut[i] = 0;
                    // 松弛更新
                    else if(cut[i] > cut[j+1] + 1)
                        cut[i] = cut[j+1] + 1;
                }
            }
        }
        return cut[0];
    }
};