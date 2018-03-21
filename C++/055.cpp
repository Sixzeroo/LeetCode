class Solution {
public:
    bool canJump(vector<int>& nums) {
        int st = 0, len = nums.size();
        // 贪心算法，每次都期望走到最远
        while(st < len-1)
        {
            int maxi = st,maxv = st;
            for(int i = st+1; i<=st+nums[st];i++)
            {
                if(i+nums[i] > maxv)
                {
                    maxi = i;
                    maxv = i+nums[i];
                }
            }
            if(maxi == st)
                break;
            else
                st = maxi;
        }
        return st >= len-1;
    }
};