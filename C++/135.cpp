class Solution {
public:
    // 找到谷底往两边扩方案， O(n)
    int candy(vector<int>& ratings) {
        int len = ratings.size();
        int res = 0;
        vector<int> nums(len, 1);
        for(int i = 1; i < len; i++)
        {
            if(ratings[i] > ratings[i-1])
                nums[i] = nums[i-1] + 1;
        }
        for(int i = len - 2; i >= 0; i--)
        {
            if(ratings[i] > ratings[i+1])
                nums[i] = max(nums[i], nums[i+1] + 1);
            res += nums[i];
        }
        res += nums[len - 1];
        return res;
    }
};