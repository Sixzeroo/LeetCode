class Solution {
public:
    int getStrNum(string &s, int l, int r)
    {
        int res = 0;
        for(int i = l; i <= r; i++)
            res = res*10 + s[i] - '0';
        return res;
    }
    
    int numDecodings(string s) {
        int len = s.size();
        if(len == 0) return 0;
        if(len == 1) return s[0] == '0' ? 0 : 1;
        // dp[i] 表示从i到len-1能够编码的方案
        vector<int> dp(len+1, 0);
        // 表示有两位数的时候+1
        dp[len] = 1;
        int n1 = getStrNum(s, len-1, len-1), n2;
        dp[len-1] = n1 > 0 ? 1 : 0;
        for(int i = len-2; i >= 0; i--)
        {
            n1 = getStrNum(s, i, i);
            // 如果为0在开头，则无法编码
            if(n1 == 0) dp[i] = 0;
            else
            {
                n2 = getStrNum(s, i, i+1);
                dp[i] = dp[i+1];
                // 能够进行两位数编码时加上后面的编码数
                if(n2 > 0 && n2 <= 26) dp[i] += dp[i+2];
            }
        }
        return dp[0];
    }
};