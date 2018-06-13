class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        int l = 0, r = len -1, m;
        while(l < r)
        {
            m = l + (r - l)/2;
            // 不使用m-1, 因为可能会错过最小值
            if(nums[m] < nums[r])
                r = m;
            else if (nums[m] == nums[r])
                r --;
            else
                l = m + 1;
        }
        return nums[l];
    }
};