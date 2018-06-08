class Solution {
public:
    // 找出所有递增部分
    int maxProfit(vector<int>& prices) {
        int res = 0, len = prices.size();
        for(int i = 1; i < len; i++)
            if(prices[i] > prices[i-1])
                res += (prices[i] - prices[i-1]);
        return res;
    }
};