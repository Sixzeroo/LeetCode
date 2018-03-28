class Solution {
public:
    int par[3000];
    
    void init(int n)
    {
        for(int i=1;i<=n;i++)
            par[i] = i;
    }
    
    int find(int x)
    {
        if(par[x] == x) return x;
        else return par[x] = find(par[x]);
    }
    
    void unite(int x, int y)
    {
        x = find(x);
        y = find(y);
        if(x == y) return;
        par[y] = x;
    }
    
    // 并查集模板题
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int len = edges.size();
        init(len);
        for(auto i:edges)
        {
            int a = find(i[0]), b = find(i[1]);
            if(a==b)
                return i;
            else
                unite(i[0], i[1]);
        }
    }
};