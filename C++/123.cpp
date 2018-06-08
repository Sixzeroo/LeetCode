class Solution {
public:
    // 分两次买，第二次贪心要在第一次的基础上
    int maxProfit(vector<int>& prices) {
        int sell1 = 0, sell2 = 0, buy1 = INT_MIN, buy2 = INT_MIN;
        int len = prices.size();
        for(int i = 0; i < len; i++)
        {
            buy1 = max(buy1, -prices[i]);  // 找到买入价最小的
            sell1 = max(sell1, prices[i] + buy1);
            buy2 = max(buy2, sell1 - prices[i]); // 在第一次交易的基础上找到买入价最小的
            sell2 = max(sell2, prices[i] + buy2);
        }
        return sell2;
    }
};