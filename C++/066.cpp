class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int cap = 1, len=digits.size();
        vector<int> res;
        // 注意进位
        for(int i=len-1; i>=0; i--)
        {
            int tem = digits[i] + cap;
            res.push_back(tem%10);
            cap = tem/10;
        }
        if(cap) res.push_back(1);
        reverse(res.begin(), res.end());
        return res;
    }
};