class Solution {
public:
    int m,n;
    
    // 使用dfs把一个区域的1都标记为0
    void dfs2(vector<vector<char> >& board, int i, int j)
    {
        for(int t=0;t<4;t++)
        {
            int tx = i+po[t][0];
            int ty = j+po[t][1];
            if(tx>=m || tx<0 || ty >=n || ty<0) continue;
            if(board[tx][ty] == '1')
            {
                board[tx][ty] = '0';
                dfs2(board, tx, ty);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& B) {
        if(B.size() == 0)return 0;
        m=B.size(), n=B[0].size();
        int t = 0, i=0, j=0;  // 为了初识从（0，0）开始
        int res = 0;
        // 依次查找1
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
            {
                if(B[i][j] == '1')
                {
                    res ++;
                    dfs2(B, i, j);
                }
            }
        return res;
    }
};