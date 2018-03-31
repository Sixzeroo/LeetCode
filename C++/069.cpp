class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        int l = 0, r = INT_MAX, m;
        // 二分法 在整数范围内进行查找
        while(1)
        {
            m = l+(r-l)/2;
            if(m > x/m)
                r = m-1;
            else
            {
                if(m+1 > x/(m+1))
                    return m;
                l = m+1;
            }
        }
    }
};