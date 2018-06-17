/*
* 暴力解法
*
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        // 暴力对比
        if(needle.length() == 0)
            return 0;
        for(int i=0;i<haystack.length();++i)
        {
            int end = 0;
            for(int j = 0;j<needle.length();++j)
            {
                if(i+j >= haystack.length() || needle[j] != haystack[i+j])
                {
                    end = 1;
                    break;
                }
            }
            if(!end)
            {
                return i;
            }
        }
        return -1;
    }
};

/*
* KMP算法
*/

class Solution {
public:
    int strStr(string s, string p) {
        int len = p.size();
        if(len == 0) return 0;
        // 生成next数组
        vector<int> next(len, 0);
        getNext(next, p);
        // 两个数组的遍历指针
        int i = 0, j = 0;
        while(i < s.size() && j < len)
        {
            if(s[i] == p[j])
            {
                i++;
                j++;
            }
            else
            {
                if(j == 0) i++;
                // 根据next数组中的信息进行重新指向
                else j = next[j];
            }
        }
        return j == len ? i - j : -1;
    }
    
    void getNext(vector<int> &next, string p)
    {
        next[0] = -1;
        // k表示最长前缀后缀的长度
        int k = -1, i = 0;
        // 计算到最后一位
        while(i < p.size() - 1)
        {
            // 相匹配的时候对next数组赋值
            if(k == -1 || p[i] == p[k])
                next[++i] = ++k;
            else
                k = next[k];
        }
    }
};