class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int first = nums.size(), len = nums.size();
        // 倒序查找第一个升序数
        for(int i=len-1; i>0;--i)
        {
            if(nums[i] > nums[i-1])
            {
                first = i-1;
                break;
            }
        }
        if(first == len)
            reverse(nums.begin(), nums.end());
        else
        {
            int second = len-1;
            // 在后面找一个刚好比这个数大一点的数和其互换
            for(int i=first + 1;i<len;++i)
            {
                if(nums[i]<=nums[first])
                {
                    second = i-1;
                    break;
                }
            }
            swap(nums[first], nums[second]);
            // 反转后面的部分
            reverse(nums.begin()+first+1, nums.end());
        }
    }
};