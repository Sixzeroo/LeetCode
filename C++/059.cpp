class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > matrix(n, vector<int>(n, 0));
        int num = 1;
        int m = n;
        int sm = 0, sn = 0;
        // 模拟法
        while(m>sm && n>sn)
        {
            for(int i=sn;i<n;i++)
                matrix[sm][i]=num++;
            sm++;
            for(int i=sm;i<m;i++)
                matrix[i][n-1]=num++;
            n--;
            if(m<=sm || n<=sn) break;
            for(int i=n-1;i>=sn;i--)
                matrix[m-1][i]=num++;
            m--;
            for(int i=m-1;i>=sm;i--)
                matrix[i][sn]=num++;
            sn++;
        }
        return matrix;
    }
};