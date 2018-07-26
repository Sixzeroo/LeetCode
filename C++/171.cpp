class Solution {
public:
    int titleToNumber(string s) {
        int res = 0, len = s.size();
        for(int i = 0; i < len; i++)
            res = res * 26 + s[i] - 'A' + 1;
        return res;
    }
};