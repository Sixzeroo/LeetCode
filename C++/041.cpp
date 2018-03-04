class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // 桶排序思想
        bool arr[1000000];
        memset(arr, false, sizeof(arr));
        vector<int>::iterator end = nums.end();
        for(vector<int>::iterator it = nums.begin(); it!=end; ++it)
        {
            if(*it >= 0)
                arr[*it] = true;
        }
        for(int i=1;i<1000000; ++i)
            if(arr[i] == false)
                return i;
    }
};