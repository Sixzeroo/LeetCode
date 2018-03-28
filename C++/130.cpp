class Solution {
public:
    int po[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    int m,n;
    
    // 使用dfs把没有被包围的O标记出来
    void dfs(vector<vector<char> >& board, int i, int j)
    {
        for(int t=0;t<4;t++)
        {
            int tx = i+po[t][0];
            int ty = j+po[t][1];
            if(tx>=m || tx<0 || ty >=n || ty<0) continue;
            if(board[tx][ty] == 'O')
            {
                board[tx][ty] = '1';
                dfs(board, tx, ty);
            }
        }
    }
    
    void solve(vector<vector<char>>& B) {
        if(B.size() == 0)return;
        m=B.size(), n=B[0].size();
        int t = 0, i=-1, j=0;  // 为了初识从（0，0）开始
        // 从四周开始找没有被包围的O
        while(t<4)
        {
            int tx = i+po[t][0];
            int ty = j+po[t][1];
            if(tx>=m || tx<0 || ty >=n || ty<0)
            {
                t++;
                continue;
            }
            if(B[tx][ty] == 'O')
            {
                B[tx][ty] = '1';
                dfs(B, tx, ty);
            }
            i = tx;
            j = ty;
        }
        // 填平内部的O
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
                if(B[i][j] == 'O') B[i][j] = 'X';
        // 没有被包围的O改回来
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
                if(B[i][j] == '1') B[i][j] = 'O';
    }
};