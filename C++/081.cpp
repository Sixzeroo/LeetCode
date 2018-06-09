class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int len = nums.size();
        if(len == 0) return false;
        int l = 0, r = len - 1, m;
        while(l <= r)
        {
            m = (l + r) >> 1;
            if(nums[m] == target)
                return true;
            while(nums[m] == nums[l] && nums[m] == nums[r]) 
            {
                l++;
                r--;
            }
            // 二分法，每一个区间都可能是一个断崖式的排序，需要比较四种情况
            if(nums[m] >= nums[l])
            {
                if(target >= nums[l] && target < nums[m]) r = m - 1;
                else l = m + 1;
            }
            else
            {
                if(target <= nums[r] && target > nums[m]) l = m + 1;
                else r = m - 1;
            }
        }
        return false;
    }
};