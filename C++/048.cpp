class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 && matrix[0].size() == 0) return;
        int len=matrix.size();
        for(int i=0; i<(len+1)/2; i++)
        {
            for(int j=0; j<len/2; j++)
            {
                // 实现轮转
                int tem = matrix[i][j];
                matrix[i][j] = matrix[len-1-j][i];
                matrix[len-1-j][i] = matrix[len-1-i][len-1-j];
                matrix[len-1-i][len-1-j] = matrix[j][len-1-i];
                matrix[j][len-1-i] = tem;
            }
        }
    }
};