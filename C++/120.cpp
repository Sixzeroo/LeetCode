class Solution {
public:
    // dp求解
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        if(m == 0) return 0;
        vector<vector<int> > dp(m, vector<int>(m, 0));
        for(int i = 0; i < m; i++) dp[m-1][i] = triangle[m-1][i];
        for(int i = m-2; i >= 0; i--)
        {
            // 状态转移公式
            for(int j = 0; j <= i; j++)
                dp[i][j] = min(dp[i+1][j], dp[i+1][j+1]) + triangle[i][j];
        }
        return dp[0][0];
    }
};