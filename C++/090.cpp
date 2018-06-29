class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> out;
        if (nums.empty())
            return {};
        sort(nums.begin(), nums.end());
        helper(nums, out, res, 0);
        return res;
    }
    void helper(vector<int>& nums, vector<int>& out, vector<vector<int>>& res, int pos) {
        if (find(res.begin(), res.end(), out) == res.end())
            res.push_back(out);
        for (int i = pos; i < nums.size(); i++) {
            out.push_back(nums[i]);
            helper(nums, out, res, i + 1);
            out.pop_back();
        }
    }
};