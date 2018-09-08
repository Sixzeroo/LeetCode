class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int len = nums.size();
        unordered_map<int, int> m;
        int sum = 0, res = 0;
        m[0] = 1;
        for(int i = 0; i < len; i++)
        {
            sum += nums[i];
            // 加上剩余的值出现的次数
            res += m[sum - k];
            m[sum] ++;
        }
        return res;
    }
};