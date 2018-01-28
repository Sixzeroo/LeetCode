class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = nums[0]+nums[1]+nums[2],len = nums.size();
        int minv = abs(res - target);
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<len;i++)
        {
            for(int j=i+1,k=len -1;j<k;)
            {
                int tmp = abs(nums[i]+nums[j]+nums[k]-target);
                if(tmp<minv)
                {
                    minv = tmp;
                    res = nums[i]+ nums[j] + nums[k];
                }
                if(nums[i]+nums[j]+nums[k]>=target)
                    k--;
                else
                    j++;
            }
        }
        return res;
    }
};