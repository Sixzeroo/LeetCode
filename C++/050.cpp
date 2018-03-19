class Solution {
public:
    double myPow(double x, int n) {
        // 负数幂判断
        bool flag = false;
        if(n<0) 
        {
            flag = true; 
            n=-n;
        }
        // 快速幂运算
        double res=1, tem = x;
        while(n!=0)
        {
            if(n%2) res*=tem;
            tem*=tem;
            n/=2;
        }
        return flag?1/res:res;
    }
};