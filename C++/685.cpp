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
    
    // 并查集
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int len = edges.size();
        init(len);
        vector<int> indegre(len, 0), outdegre(len, 0);
        vector<vector<int> > problem_edge;
        int node = 0;
        // 统计入度，找到入度为2的点
        for(auto i:edges)
        {
            indegre[i[1]]++;
            if(indegre[i[1]] == 2) node = i[1];
        }
        int flag=0;
        for(auto i:edges)
        {
            if(i[1] == node)
            {
                problem_edge.push_back(i);
                continue;
            }
            // 有环的情况
            int a = find(i[0]), b= find(i[1]);
            if(a == b) 
                return i;
            unite(i[0], i[1]);
        }
        // 无环的情况，从入度为2的节点入手
        for(auto i:problem_edge)
        {
            int a = find(i[0]), b= find(i[1]);
            if(a == b) return i;
            else unite(a,b);
        }
    }
};