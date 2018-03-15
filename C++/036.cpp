class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 使用位运算，用一个数表示一行、一排、一个空格的数的情况
        vector<int> row(9, 0);
        vector<int> col(9, 0);
        vector<int> block(9, 0);
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                if(board[i][j] != '.')
                {
                    // 比较的数
                    int tmp = 1 << (board[i][j] - '0');
                    // 使用逻辑与判断数字是否出现过
                    if(row[i] & tmp || col[j] & tmp || block[i/3 *3 + j/3] & tmp)
                    {
                        cout<<i<<" "<<j<<endl;
                        return false;
                    }
                    row[i] = row[i] | tmp;
                    col[j] = col[j] | tmp;
                    block[i/3 *3 + j/3] = block[i/3 *3 + j/3] | tmp;
                }
            }
        }
        return true;
    }
};