class Solution {
public:
    // Minimax算法，dp思路
    int getMoneyAmount(int n) {
        vector<vector<int> > dp(n + 1, vector<int>(n + 1, INT_MAX));
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= n; j++)
            {
                if(i == j) dp[i][j] = 0;
                else if (i > j) dp[i][j] = 0;
            }
        for(int i = 1; i <= n; i++)
            for(int j = 0; j <= n-i; j++)
            {
                int tem = INT_MAX;
                for(int k = j; k <= j+i; k++)
                {
                    if(k == 0)
                        tem = min(tem, k + dp[k+1][j+i]);
                    else if(k == n)
                        tem = min(tem, k + dp[j][k-1]);
                    else
                        tem = min(tem, k + max(dp[j][k-1], dp[k+1][j+i]));
                }
                dp[j][j+i] = tem;
            }
        return dp[0][n];
    }
};