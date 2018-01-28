class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int len = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<len;i++)
        {
            if(i==0 || nums[i] != nums[i-1]) // 去重
            {
                for(int j = i+1;j<len ;j++)
                {
                    if(j== i+1 || nums[j] != nums[j-1]) // 去重
                    {
                        for(int k = j+1,h=len-1;k<h;)
                        {
                            if(nums[i]+nums[j]+nums[k]+nums[h] == target)
                            {
                                vector<int> tmp = {nums[i],nums[j],nums[k],nums[h]};
                                res.push_back(tmp);
                                k++;
                                while(k<h && nums[k] == nums[k-1]) k++;
                            }
                            else if(nums[i]+nums[j]+nums[k]+nums[h] < target)
                            {
                                k++;
                                while(k<h && nums[k] == nums[k-1]) k++;
                            }
                            else
                            {
                                h--;
                                while(k<h && nums[h] == nums[h+1]) h--;
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};