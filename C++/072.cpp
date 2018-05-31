class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size(), len2 = word2.size();
        vector<vector<int> > dp(len1+1, vector<int>(len2+1, 0));
        // dp问题
        for(int i = 0; i <= len1; i++)
            for(int j = 0; j <= len2; j++)
            {
                if(i == 0 && j == 0) continue;
                if(i == 0) dp[i][j] = dp[i][j-1] + 1;
                if(j == 0) dp[i][j] = dp[i-1][j] + 1;
                if(i == 0 || j == 0) continue;
                // 两种情况，代表增、删、取代（相等）
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = min(min(dp[i-1][j-1], dp[i-1][j] + 1), dp[i][j-1] + 1);
                else
                    dp[i][j] = min(min(dp[i-1][j] + 1, dp[i][j-1] + 1), dp[i-1][j-1] + 1);
            }
        return dp[len1][len2];
    }
};