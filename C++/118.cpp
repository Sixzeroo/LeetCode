class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int> local;
        for(int i = 1; i <= numRows; i++)
        {
            local.push_back(1);
            for(int j = i - 2; j > 0; j--)
                local[j] = local[j] + local[j-1];
            res.push_back(local);
        }
        return res;
    }
};