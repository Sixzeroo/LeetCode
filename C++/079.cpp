class Solution {
public:
    vector<vector<int> > v = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    // 回溯法进行搜索
    bool existStart(vector<vector<char>>& board, const string word, int now_index, vector<vector<bool> > &used, int x, int y)
    {
        int len = word.size();
        if(now_index == len - 1)
            return board[x][y] == word[len - 1];
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < 4; i++)
        {
            int dx = x + v[i][0], dy = y + v[i][1];
            if(dx < 0 || dx >= m) continue;
            if(dy < 0 || dy >= n) continue;
            if(used[dx][dy]) continue;
            if(board[dx][dy] != word[now_index + 1]) continue;
            used[dx][dy] = true;
            bool res = existStart(board, word, now_index+1, used, dx, dy);
            if(res) return true;
            used[dx][dy] = false;
        }
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int len = word.size();
        if(len == 0) return true;
        int m = board.size();
        if(m == 0) return false;
        int n = board[0].size();
        if(n == 0) return false;
        vector<vector<bool> > used(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] != word[0]) continue;
                used[i][j] = true;
                int res = existStart(board, word, 0, used, i, j);
                if(res) return true;
                used[i][j] = false;
            }
        }
        return false;
    }
};