class Solution {
public:
    // 使用异或门
    int singleNumber(vector<int>& nums) {
        int i = 0;
        for(int it: nums)
            i ^= it;
        return i;
    }
};