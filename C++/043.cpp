class Solution {
public:
    string multiply(string num1, string num2) {
        string res(num1.size()+num2.size(), '0');
        int len1 = num1.size(), len2=num2.size();
        for(int i=len1-1; i>=0; i--)
        {
            int carry = 0;
            for(int j=len2-1; j>=0; j--)
            {
                int tem = (res[i+j+1]-'0') + (num1[i]-'0')*(num2[j]-'0') + carry;
                res[i+j+1] = tem%10 + '0';
                carry = tem/10;
            }
            // 最后的进位的处理，因为是0不会产生进位
            res[i] += carry;
        }
        for(int i=0; i<len1+len2; i++)
            if(res[i]!='0')
                return res.substr(i);
        return "0";
    }
};