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