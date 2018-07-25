class Solution {
public:
    // 贪心思路
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        int res = nums[0];
        int curMax = nums[0], preMax = nums[0];
        int curMin = nums[0], preMin = nums[0];
        for(int i = 1; i < len; i++)
        {
            curMax = max(nums[i], max(nums[i] * preMax, nums[i] * preMin));
            curMin = min(nums[i], min(nums[i] * preMax, nums[i] * preMin));
            res = max(res, curMax);
            preMax = curMax;
            preMin = curMin;
        }
        return res;
    }
};