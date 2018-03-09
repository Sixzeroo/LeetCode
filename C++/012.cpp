class Solution {
public:
    string intToRoman(int num) {
        // 贪心算法
        string res = "";
        vector<int> val {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> ch{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        for(int i=0;i<val.size();i++)
        {
            while(num>=val[i])
            {
                num -= val[i];
                res.append(ch[i]);
            }
        }
        return res;
    }
};