class Solution {
public:
    // dp 
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, 0);
        for(int i = 1; i <= amount; i++)
        {
            int minv = INT_MAX;
            for(int j = 0; j < coins.size(); j++)
            {
                if(i >= coins[j] && dp[i-coins[j]] != -1)
                    minv = min(minv, dp[i-coins[j]] + 1);
            }
            dp[i] = minv == INT_MAX ? -1 : minv;
        }
        return dp[amount];
    }
};