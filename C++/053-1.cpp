class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0], sum =0;
        for(int i=0;i<nums.size();i++)
        {
            sum = max(nums[i], sum + nums[i]);
            res = max(res, sum);
        }
        return res;
    }
};