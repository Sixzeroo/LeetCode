class Solution {
public:
    // 使用set求解，先得到不重复的集合
    int singleNumber(vector<int>& nums) {
        set<int> a;
        long long sum1 = 0;
        for(auto i: nums)
        {
            sum1 += i;
            a.insert(i);
        }
        long long sum2 = 0;
        for(auto i: a)
            sum2 += i;
        return (3*sum2 - sum1)/2;
    }
};