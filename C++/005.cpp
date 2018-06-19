class Solution {
public:
    // Manacher 算法
    string longestPalindrome(string s) {
        // 添加辅助字符#
        string new_s;
        new_s.push_back('#');
        for(int i = 0; i < s.size(); i++)
        {
            new_s.push_back(s[i]);
            new_s.push_back('#');
        }
        s = new_s;
        int len = s.size();
        if(len == 0) return 0;
        // 回文半径数组
        vector<int> pArr(len, 0);
        // C表示回文中心， R表示回文右边界
        int C = -1, R = -1;
        int maxv = INT_MIN, maxi = 0;
        for(int i = 0; i < len; i++)
        {
            // 在回文右边界里面与否的区分
            // 此时pArr表示的是起码不用验的区域 
            pArr[i] = R > i ? min(pArr[2*C - i], R - i) : 1;
            // 区域没有越界
            while(i + pArr[i] < len && i - pArr[i] > -1)
            {
                // 情况1+4 扩充
                if(s[i + pArr[i]] == s[i - pArr[i]])
                    pArr[i]++;
                // 情况2+3
                else
                    break;
            }
            if(i + pArr[i] > R)
            {
                R = i + pArr[i];
                C = i;
            }
            if(maxv < pArr[i])
            {
                maxv = pArr[i];
                maxi = i;
            }
        }
        string res;
        for(int i = maxi - maxv + 1; i <= maxi + maxv - 1; i++)
            if(s[i] != '#') res.push_back(s[i]);
        return res;
    }
};