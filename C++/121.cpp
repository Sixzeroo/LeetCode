class Solution {
public:
    // 逆向思维，从后往前扫描
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len == 0) return 0;
        int maxv = prices[len-1];
        for(int i = len-1; i >= 0; i--)
        {
            maxv = max(prices[i], maxv);
            prices[i] = maxv - prices[i];
        }
        return *max_element(prices.begin(), prices.end());
    }
};