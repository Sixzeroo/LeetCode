class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int res = 0, len = nums.size();
        int count = 0, ptr = 0;
        // 简单的遍历判断
        for(int i = 0; i < len; i++)
        {
            if(i == 0 || nums[i] != nums[i-1])
            {
                res ++;
                count = 0;
                nums[ptr++] = nums[i];
                continue;
            }
            if(nums[i] == nums[i-1] && count < 1)
            {
                count ++;
                res ++;
                nums[ptr++] = nums[i];
                continue;
            }
        }
        for(int i = 0; i < res; i++)
            cout<<nums[i]<<" ";
        cout<<endl;
        return res;
    }
};