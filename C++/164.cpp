class Solution {
public:
    // 桶排序 时间复杂度O(n)
    int maximumGap(vector<int>& nums) {
        int len = nums.size();
        if(len < 2) return 0;
        int minv = nums[0], maxv = nums[0];
        for(int i : nums)
        {
            minv = min(minv, i);
            maxv = max(maxv, i);
        }
        
        // 每个桶的跨度
        int span = (maxv - minv) / len + 1;
        // 桶
        vector<vector<int> > bucket((maxv - minv) / span + 1);
        
        // 桶中保存的是这个桶的最大值和最小值，因为前面计算的跨度，一定能够得到最大的差值
        for(int i : nums)
        {
            int index = (i - minv) / span;
            if(bucket[index].empty())
            {
                bucket[index].push_back(i);
                bucket[index].push_back(i);
            }
            else
            {
                bucket[index][0] = min(bucket[index][0], i);
                bucket[index][1] = max(bucket[index][1], i);
            }
        }
        
        int res = 0, pre = 0;
        for(int i = 1; i < bucket.size(); i++)
        {
            if(bucket[i].empty()) continue;
            res = max(res, bucket[i][0] - bucket[pre][1]);
            pre = i;
        }
        return res;
    }
};