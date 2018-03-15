class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        // 用来进行对比的map
        unordered_map<string, int> contrast;
        for(string s : words)
        {
            contrast[s]++;
        }
        int slen = s.length(), wlen = words[0].length(), wsize = words.size();
        // 依次截取一定长度的字符串进行匹配
        for(int i=0; i<slen-wsize*wlen+1; i++)
        {
            unordered_map<string, int> tem;
            int j=0;
            for(; j<wsize; j++)
            {
                // 分割以后的每一个字符串
                string stem = s.substr(i+j*wlen, wlen);
                // 判断是否在匹配字符串组中
                if(contrast.find(stem) != contrast.end())
                {
                    tem[stem]++;
                    // 出现次数超过1，放弃
                    if(tem[stem] > contrast[stem])
                        break;
                }
                else
                    break;
            }
            if(j == wsize)
                res.push_back(i);
        }
        return res;
    }
};