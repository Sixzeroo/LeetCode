class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size();
        // 使用栈来保存一个递增的序列
        stack<int> s;
        int res = 0;
        for(int i = 0; i < len; i++)
        {
            while(!s.empty() && heights[s.top()] > heights[i])
            {
                int tem = s.top();
                s.pop();
                // 计算不在序列内的区块的面积
                int curArea = s.empty() ? i*heights[tem] : (i - s.top() - 1)*heights[tem];
                res = max(res, curArea);
                // cout<<i<<" "<<res<<endl;
            }
            s.push(i);
        }
        // 对递增序列中的序列面积进行计算
        while(!s.empty())
        {
            int tem = s.top();
            s.pop();
            int curArea = s.empty() ? len*heights[tem] : (len - s.top() - 1) * heights[tem];
            res = max(res, curArea);
            // cout<<tem<<" "<<res<<endl;
        }
        return res;
    }
};