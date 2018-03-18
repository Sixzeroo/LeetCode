class Solution {
public:
    int jump(vector<int>& nums) {
        // 贪心思想
        int len = nums.size(), step = 0, start = 0;
        while(start < len-1)
        {
            step ++;
            int maxi=0, maxv=0;
            // 找到能够走最远的那一步
            for(int i=1; i<=nums[start]; i++)
            {
                // 超过终点
                if(start+i >= len-1) 
                    return step;
                if(start+i < len && maxv < i+nums[start+i])
                {
                    maxi = i;
                    maxv = i+nums[start+i];
                }
            }
            start += maxi;
        }
        return step;
    }
};