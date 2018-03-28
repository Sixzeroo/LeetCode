class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> t; // map表示每个数所在集合的连续数的个数
        int res = 0;
        for(int i:nums)
        {
            // 依次考虑新的数
            if(t.find(i) == t.end() || t[i] == 0)
            {
                // 只更新两端，因为合并的时候只考虑两端
                t[i] = t[i-t[i-1]] = t[i+t[i+1]] = t[i-1] + t[i+1] + 1;
                res = max(res, t[i]);
            }
        }
        return res;
    }
};