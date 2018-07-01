class Solution {
public:
    // Minimax 算法
    bool canWin(vector<int> &nums, int sum1, int sum2, int l, int r, int player)
    {
        if(l > r) return sum1 >= sum2;
        if(l == r)
        {
            if(player == 1)
                return sum1 + nums[l] >= sum2;
            else
                return sum2 + nums[l] > sum1;
        }
        // 决策过程
        if(player == 1)
        {
            return !canWin(nums, sum1 + nums[l], sum2, l+1, r, 2) || !canWin(nums, sum1 + nums[r], sum2, l, r-1, 2);
        }
        else if(player == 2)
        {
            return !canWin(nums, sum1, sum2 + nums[l], l+1, r, 1) || !canWin(nums, sum1, sum2 + nums[r], l, r-1, 1);
        }
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        return canWin(nums, 0, 0, 0, nums.size()-1, 1);
    }
};