class Solution {
public:
    int getNum(char a)
    {
        switch(a){
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
                
        }
    }
    
    int romanToInt(string s) {
        int res = 0, tmp = 10000;
        for(int i=0;i<s.size();i++)
        {
            int val = getNum(s[i]);
            if(val > tmp)
                res = res + val - 2*tmp;
            else
                res += val;
            tmp = val;
        }
        return res;
    }
};