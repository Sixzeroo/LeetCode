class Solution {
public:
    // 三指针思路：0放置指针，2放置指针，遍历指针
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        int target = 1;
        for(int i = 0, j = 0, n = len - 1; j <= n;)
        {
            if(nums[j] > target)
                swap(nums[j], nums[n--]);
            else if(nums[j] < target)
                swap(nums[j++], nums[i++]);
            else
                j++;
        }
    }
};