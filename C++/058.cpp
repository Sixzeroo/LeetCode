class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0,tem=s.length()-1;
        while(s[tem] == ' ') tem--;
        for(;tem>=0;tem--,res++)
            if(s[tem] ==' ') break;
        return res;
    }
};