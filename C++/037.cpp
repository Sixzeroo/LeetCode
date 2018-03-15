class Solution {
public:
    // 判断一个字符放进去合不合理
    bool isValidSudoku(vector<vector<char>>& board, int a, int b, char c) {
        for(int i=0; i<9; i++)
        {
            if(board[i][b] == c || board[a][i] == c || board[a/3*3 + i%3][b/3*3 + i/3] == c) return false;
        }
        return true;
    }
    
    bool bfs(vector<vector<char> > &board, int a,int b)
    {
        // 边界确定
        if(a == 9) return true;
        if(b == 9) return bfs(board, a+1, 0);
        // 去除已经确定数字的情况
        if(board[a][b] != '.') return bfs(board, a, b+1);
        // 依次枚举
        for(char i='1'; i<='9'; i++)
        {
            if(isValidSudoku(board, a, b, i))
            {
                board[a][b] = i;
                if(bfs(board, a, b+1)) return true;
                board[a][b] = '.';
            }
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        bfs(board, 0, 0);
    }
};