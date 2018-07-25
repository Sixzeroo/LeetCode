class Solution {
public:
    void reverseWords(string &s) {
        int len = s.size();
        // 去除头部的空格
        int i = 0;
        while(s[i] == ' ' && i < len)
            i++;
        s.erase(0, i);
        // 去除尾部的空格
        len = s.size();
        i = len - 1;
        while(s[i] == ' ' && i >= 0)
            i--;
        s.erase(i+1, len);
        // 去除中间多余的空格
        len = s.size();
        int count = 0;
        for(int i = 0; i < len; i++)
        {
            if (i > 0 && s[i] == ' ' && s[i-1] == ' ')  continue;
            s[count++] = s[i];
        }
        s.erase(count, len);
        // 整体互换
        reverse(s.begin(), s.end());
        // 中间各个单词互换
        len = s.size();
        for(int i = 0; i < len; i++)
        {
            if(s[i] != ' ')
            {
                int j = i + 1;
                while(j < len && s[j] != ' ')
                    j ++;
                reverse(s.begin() + i, s.begin() + j);
                i = j - 1;
            }
        }
    }
};