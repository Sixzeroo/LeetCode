class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int len = nums.size(), pos = -1;
        // 二分法查找
        int l = 0, r = nums.size()-1;
        while(l<=r)
        {
            int m = (l+r)/2;
            if(nums[m] > target)
                r = m-1;
            else if(nums[m] < target)
                l = m+1;
            else
            {
                pos = m;
                break;
            }
        }
        // 确定范围
        if(pos == -1)
        {
            res.push_back(pos);
            res.push_back(pos);
        }
        else
        {
            int lres = pos, rres = pos;
            while(lres >0 && nums[lres-1] == nums[lres])
                lres --;
            while(rres < len-1 && nums[rres+1] == nums[rres])
                rres ++;
            res.push_back(lres);
            res.push_back(rres);
        }
        return res;
    }
};