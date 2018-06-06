class Solution {
public:
    // 获取切片的情况
    vector<int> getSlice(vector<vector<char>>& matrix, int h)
    {
        vector<int> ret;
        int len = matrix[0].size();
        for(int i = 0; i < len; i++)
        {
            int tem = h, count = 0;
            while(tem >= 0 && matrix[tem][i] == '1')
            {
                tem --;
                count ++;
            }
            ret.push_back(count);
        }
        return ret;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int len1 = matrix.size();
        if(len1 == 0) return 0;
        int len2 = matrix[0].size();
        if(len2 == 0) return 0;
        int res = 0;
        for(int t = 0; t < len1; t++)
        {
            vector<int> heights = getSlice(matrix, t);
            int len3 = heights.size();
            // 使用栈来保存一个递增的序列
            stack<int> s;
            int tem_res = 0;
            for(int i = 0; i < len3; i++)
            {
                while(!s.empty() && heights[s.top()] > heights[i])
                {
                    int tem = s.top();
                    s.pop();
                    // 计算不在序列内的区块的面积
                    int curArea = s.empty() ? i*heights[tem] : (i - s.top() - 1)*heights[tem];
                    tem_res = max(tem_res, curArea);
                    // cout<<i<<" "<<tem_res<<endl;
                }
                s.push(i);
            }
            // 对递增序列中的序列面积进行计算
            while(!s.empty())
            {
                int tem = s.top();
                s.pop();
                int curArea = s.empty() ? len3*heights[tem] : (len3 - s.top() - 1) * heights[tem];
                tem_res = max(tem_res, curArea);
                // cout<<tem<<" "<<tem_res<<endl;
            }
            res = max(res, tem_res);
        }
        return res;
    }
};