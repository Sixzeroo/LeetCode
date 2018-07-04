/*
*  Minimax递归方法
*/
class Solution {
public:
    // Minimax 算法
    
    int f(vector<int>& nums, int l, int r)
    {
        if(l == r) return nums[l];
        return max(nums[l] + s(nums, l+1, r), nums[r] + s(nums, l, r-1));
    }
    
    int s(vector<int>& nums, int l, int r)
    {
        if(l == r) return 0;
        return min(f(nums, l+1, r), f(nums, l, r-1));
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return true;
        int sum = 0;
        for(int i : nums) sum += i;
        int winer = f(nums, 0, len-1);
        // sum+1 表示其一定比sum的一半要大才行，消除四舍五入的因素
        return winer >= (sum+1)/2;
    }
};

/*
*  dp 优化
*/

class Solution {
public:
    // Minimax 算法
    bool PredictTheWinner(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return true;
        vector<vector<int> > f(len, vector<int>(len, 0)), s(len, vector<int>(len, 0));
        int sum = 0;
        for(int i : nums) sum += i;
        for(int j = 0; j < len; j++)
        {
            f[j][j] = nums[j];
            for(int i = j-1; i >= 0; i--)
            {
                f[i][j] = max(nums[i] + s[i+1][j], nums[j] + s[i][j-1]);
                s[i][j] = min(f[i+1][j], f[i][j-1]);
            }
        }
        return f[0][len-1] >= (sum+1)/2;
    }
};