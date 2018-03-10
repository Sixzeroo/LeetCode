class Solution {
public:
    int divide(int dividend, int divisor) {
        int res = 0;
        if( divisor==0 || (dividend == INT_MIN && divisor == -1) ) return INT_MAX;
        bool flag = ((dividend<0) ^(divisor<0))?true:false;
        long long did = labs(dividend), dis = labs(divisor);
        // 位运算执行除法
        while(did >= dis)
        {
            long long tmp = dis, tmp2 = 1;
            while((tmp<<1) <= did)
            {
                tmp <<= 1;
                tmp2 <<= 1;
            }
            did -= tmp;
            res += tmp2;
        }
        return flag?-res:res;
    }
};