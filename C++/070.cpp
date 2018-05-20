class Solution {
public:
    // 斐波那契数列
    int climbStairs(int n) {
        int a = 1, b = 1, c;
        if(n == 1)
            return 1;
        for(int i = 1; i < n; i++)
        {
            c = b;
            b = a + b;
            a = c;
        }
        return b;
    }
};