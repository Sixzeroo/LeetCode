class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.size() == 0) return res;
        int m = matrix.size(), n=matrix[0].size();
        int sm = 0, sn = 0;
        // 模拟法
        while(m>sm && n>sn)
        {
            for(int i=sn;i<n;i++)
                res.push_back(matrix[sm][i]);
            sm++;
            for(int i=sm;i<m;i++)
                res.push_back(matrix[i][n-1]);
            n--;
            if(m<=sm || n<=sn) break;
            for(int i=n-1;i>=sn;i--)
                res.push_back(matrix[m-1][i]);
            m--;
            for(int i=m-1;i>=sm;i--)
                res.push_back(matrix[i][sn]);
            sn++;
        }
        return res;
    }
};