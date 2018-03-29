class Solution {
public:
    
    // n&(n-1) 消除二进制中最后的一个1
    bool isPowerOfTwo(int n) {
        return n>0 && !(n&(n-1));
    }
};