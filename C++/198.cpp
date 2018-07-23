class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int d[n+1];
        memset(d,0,sizeof(d));
        int i,j,k;
        int m=0;
        if(n==0){
            return 0;
        }else{
            if(nums.size()==1){
                return nums[0];
            }else{
                d[0] = nums[0];
                for(i=1; i <n;i++){
                    if(i - 2 >=0){
                        d[i] = max(d[i-1], d[i-2]+nums[i]);
                    }else{
                        d[i] = max(d[i-1],nums[i]);
                    }
            
                }
                return d[n-1];
            }
        }
    }
};