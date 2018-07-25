class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) return 0;
        for(int i = 0; i < len; i++)
        {
            if (i == 0 && nums[i] > nums[i+1]) return i;
            if( i == len - 1 && nums[i] > nums[i-1]) return len - 1;
            if( nums[i] > nums[i+1] && nums[i] > nums[i-1]) return i;
        }
        return len - 1;
    }
};