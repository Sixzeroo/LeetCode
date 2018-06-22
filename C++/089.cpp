class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        res.push_back(0);
        if(n == 0) return res;
        int tem = 1;
        res.push_back(1);
        for(int i = 1; i < n; i++)
        {
            tem *= 2;
            vector<int> v_tem = res;
            // 反转以后加到原来的数组中去
            reverse(v_tem.begin(), v_tem.end());
            for(int it : v_tem)
                res.push_back(it + tem);
        }
        return res;
    }
};