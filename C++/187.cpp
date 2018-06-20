class Solution {
public:
    map<char,int> dict;
    
    Solution() {
        dict.insert(make_pair('A', 0));
        dict.insert(make_pair('C', 1));
        dict.insert(make_pair('G', 2));
        dict.insert(make_pair('T', 3));
    }
    
    // 对字符串进行编码
    int stringtoint(string a)
    {
        int res = 0;
        int tem = 1;
        for(int i = 0; i < 10; i++)
        {
            res += (tem * dict[a[i]]);
            tem *= 4;
        }
        return res;
    }
    
    // 使用编码以后的hashmap，降低空间复杂度
    vector<string> findRepeatedDnaSequences(string s) {
        map<int, int> m;
        int len = s.size();
        vector<string> res;
        if(len <= 10) return res;
        for(int i = 0; i <= len - 10; i++)
        {
            string tem_s = s.substr(i, 10);
            int code = stringtoint(tem_s);
            if(m.find(code) != m.end() && m[code] == 1)
            {
                res.push_back(tem_s);
                m[code] ++;
            }
            if(m.find(code) == m.end())
                m.insert(make_pair(code, 1));
        }
        return res;
    }
};