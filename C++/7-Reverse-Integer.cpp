class Solution {
public:
    int reverse(int x) {
        int cnt=0,negative_flag = 0;
        long long res =0;
        if(x<0)
        {
            x = -x;
            negative_flag = 1;
        }
        while(x>0)
        {
            res = res*10 + x%10;
            x/=10;
        }
        if(res>INT_MAX) return 0;
        if(negative_flag)
            return -res;
        else
            return res;
    }
};