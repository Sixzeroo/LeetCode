class Solution {
public:
    int myAtoi(string str) {
        // 模拟法
        long long res = 0;
        bool neg = false;
        int i=0;
        // 忽略前面的空格
        while(str[i] == ' ')
            i++;
        // 获得+-号
        if(str.length() > 0 && str[i] == '-')
        {
            neg = true;
            ++i;
        }
        else if(str.length() > 0 && str[i] == '+')
            ++i;
        // 逐个读取
        for(;i<str.length();++i)
        {
            // 遇到非法字符中止
            if(str[i] < '0' || str[i] > '9')
                break;
            res = res*10 + (str[i] - '0');
            if(res > INT_MAX)
            {
                return neg?INT_MIN:INT_MAX;
            }
        }
        return neg?-res:res;
    }
};