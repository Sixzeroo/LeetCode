class Solution {
public:
    // 保存之前的乘积
    int numTrees(int n) {
        vector<int> dp(n+1, 1);
        for(int i = 1; i <= n; i++)
        {
            int sum = 0;
            for(int j = 0; j < i; j++)
                sum += dp[j] * dp[i-j-1];
            dp[i] = sum;
        }
        return dp[n];
    }
};