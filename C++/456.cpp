class Solution {
public:
    // 单调栈结构巧妙解法
    bool find132pattern(vector<int>& nums) {
        stack<int> s;
        int len = nums.size();
        if (len < 3) return false;
        int s3 = INT_MIN;
        for(int i = len - 1; i >= 0; i--)
        {
            if(nums[i] < s3) return true;
            while(!s.empty() && nums[i] > s.top())
            {
                s3 = max(s3, s.top());
                s.pop();
            }
            s.push(nums[i]);
        }
        return false;
    }
};