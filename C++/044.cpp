class Solution {
public:
    bool isMatch(string s, string p) {
                int plen = p.length(), slen = s.length();
        vector<vector<bool> > dp(slen + 1, vector<bool> (plen + 1, false));
        dp[slen][plen] = true;
        for(int i=slen ;i>=0;--i)
        {
            for(int j=plen-1;j>=0;--j)
            {
                // 判断第一个是否匹配
                bool match = (i<slen && (s[i] == p[j] || p[j] == '?' ));
                // 是*模式，两种方案，匹配/不匹配
                if(p[j] == '*')
                {
                    if(i==slen)
                        dp[i][j] = dp[i][j+1] ;
                    else
                        dp[i][j] = dp[i][j+1] || dp[i+1][j] || dp[i+1][j+1];
                }
                // 非*模式
                else
                    dp[i][j] = i==slen?false:(match && dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};