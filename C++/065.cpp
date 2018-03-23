class Solution {
public:
    bool isNumber(string s) {
        int i=0;
        while(s[i]==' ') i++;
        // +-号匹配
        if(s[i] == '+' || s[i] == '-') i++;
        int b=0, c=0;
        // 数字部分匹配
        while(s[i]>='0' && s[i]<='9') i++,b++;
        if(s[i]=='.')
        {
            i++;
            while(s[i]>='0' && s[i]<='9') i++,c++;
        }
        // 至少含有数字部分
        if(b==0 && c==0) return false;
        // 指数部分匹配
        if(s[i]=='e')
        {
            i++;
            if(s[i]=='+' || s[i] == '-') i++;
            int a=0;
            while(s[i]>='0' && s[i]<='9') i++,a++;
            if(a==0) return false;
        }
        while(s[i] == ' ' ) i++;
        return s[i] == '\0';
    }
};