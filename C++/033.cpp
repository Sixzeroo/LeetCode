class Solution {
public:
    int search(vector<int>& nums, int target) {
        // 找到转折点
        int pnode = 1, len=nums.size();
        for(; pnode<nums.size(); pnode++)
        {
            if(nums[pnode] < nums[pnode-1]) break;
        }
        // 二分法查找
        int left = 0, right = len-1;
        while(left <= right)
        {
            int m = (left + right)/2;
            // 坐标转换
            if(nums[(m+pnode)%len] > target)
            {
                right = m-1;
            }
            else if(nums[(m+pnode)%len] < target)
            {
                left = m+1;
            }
            else
                return (m+pnode)%len;
        }
        return -1;
    }
};