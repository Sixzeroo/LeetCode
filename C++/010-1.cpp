class Solution {
public:
    bool isMatch(string s, string p) {
        int plen = p.size(), slen = s.size();
        if(plen == 0) return slen == 0;
        // 是否匹配第一个
        bool matchfirst = (slen != 0 && (s[0] == p[0] || p[0] == '.'));
        // 是否是*模式
        if(plen >= 2 && p[1] == '*')
            return (isMatch(s, p.substr(2)) || (matchfirst && isMatch(s.substr(1), p)));
        else
            return (matchfirst && isMatch(s.substr(1), p.substr(1)));
    }
};