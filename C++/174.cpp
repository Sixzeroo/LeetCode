class Solution {
public:
    // 使用dp进行求解
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        if(m == 0) return -1;
        int n = dungeon[0].size();
        if(n == 0) return -1;
        vector<vector<int> > dp(m, vector<int>(n, 0));
        dp[m-1][n-1] = max(0 - dungeon[m-1][n-1], 0);
        // 最后和0进行比较，后面的正值不能补偿前面的损失
        for(int i = m-2; i >= 0; i--)
            dp[i][n-1] = max(dp[i+1][n-1] - dungeon[i][n-1], 0);
        for(int i = n-2; i >= 0; i--)
            dp[m-1][i] = max(dp[m-1][i+1] - dungeon[m-1][i], 0);
        for(int i = m-2; i >= 0; i--)
            for(int j = n-2; j >= 0; j--)
            {
                dp[i][j] = max(min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j], 0);
            }
        // 保证路程中的所有状态生命值都大于1
        return dp[0][0] + 1;
    }
};