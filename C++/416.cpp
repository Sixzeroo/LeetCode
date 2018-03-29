class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0, len = nums.size();
        for(auto i:nums) sum+=i;
        // 总和是奇数，不可能分成两半
        if(sum%2) return false;
        sum/=2;
        // 01背包思想，判断SUM/2大小的包能不能装满
        vector<int> dp(sum+1, 0);
        for(int i=0; i<len; i++)
            for(int j=sum; j>=nums[i]; j--)
                dp[j] = max(dp[j-nums[i]] + nums[i], dp[j]);
        return dp[sum] == sum;
    }
};