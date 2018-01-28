class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        
        sort(nums.begin(),nums.end());
        
        int len = nums.size();
        
        for(int i=0;i<len;i++)
        {
            if(i==0 || nums[i]!=nums[i-1]) // 去重
            {
                for(int j=i+1,k=len-1;j<k;)
                {
                    if(nums[i]+nums[j]+nums[k] == 0)
                    {
                        vector<int> tmp = {nums[i],nums[j],nums[k]};
                        res.push_back(tmp);
                        j++;
                        while(j<k && nums[j]==nums[j-1]) j++;
                        k=len-1;
                    }
                    else if(nums[j]+nums[k]+nums[i]>0)
                    {
                        k--;
                        while(j<k && nums[k]==nums[k+1]) k--;
                    }
                    else
                    {
                        j++;
                         while(j<k && nums[j]==nums[j-1]) j++;
                    }
                }
            }
        }
        return res;
    }
};