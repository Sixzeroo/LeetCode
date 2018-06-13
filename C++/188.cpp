class Solution {
public:
    // 贪心法思路，dp思路，考虑k在不在范围内
    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size();
        if(len == 0 || k == 0) return 0;
        if(k > len/2 && len >= 2)
            k = len/2;
        vector<int> buy(k, INT_MIN), sell(k, 0);
        for(int i = 0; i < len; i++)
        {
            for(int j = 0; j < k; j++)
            {
                if(j == 0)
                    buy[j] = max(buy[j], -prices[i]);
                else
                    buy[j] = max(buy[j], sell[j-1] - prices[i]);
                sell[j] = max(sell[j], buy[j] + prices[i]);
            }
        }
        return sell[k-1];
    }
};