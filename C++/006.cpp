class Solution {
public:
    string convert(string s, int numRows) {
        // 模拟法
        int len = s.length(), shang = 2*numRows -2;
        // 特殊情况处理
        if(len == 0) return "";
        if(numRows == 1)
            return s;
        int count = len/shang + 1;
        string res;
        int th = 0;
        // 第一排
        for(int i=0, th=0;i<count;++i)
        {
            th = 0 + i*shang;
            if(th < len)
                res.push_back(s[th]);
        }
        // 第2-(numRows-1)排
        for(int i=1;i<numRows-1;++i)
        {
            for(int j=0;j<count;++j)
            {
                th = i + j*shang;
                if(th < len)
                    res.push_back(s[th]);
                th = shang - i + j*shang;
                if(th < len)
                    res.push_back(s[th]);
            }
        }
        // 第numRows-1排
        for(int i=0;i<count;++i)
        {
            th = numRows-1 + i*shang;
            if(th < len)
                res.push_back(s[th]);
        }
        
        return res;
    }
};