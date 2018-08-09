class Solution {
public:
    vector<vector<int>> g;
    vector<int>         indegree;
private:
    void buildGraphAndIndegree(int v, vector<pair<int, int>>& edges) {
        g = vector<vector<int>>(v, vector<int>());
        indegree = vector<int>(v, 0);
        for (auto e : edges) {
            g[e.second].push_back(e.first);
            indegree[e.first]++;
        }
        return;
    }
    
    bool topologicalSort() {
        queue<int> q;
        int vertices = indegree.size();
        int cnt = 0;
        
        for (int i = 0; i < vertices; ++i) {
            if (!indegree[i]) {
                q.push(i);
                cnt++;
            }
        }
        
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for (auto v : g[u]) {
                indegree[v]--;
                if (!indegree[v]) {
                    q.push(v);
                    cnt++;
                }
            }
        }
        
        return (cnt == vertices);
    }
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        g.clear(); indegree.clear();
        buildGraphAndIndegree(numCourses, prerequisites);
        return (topologicalSort());
    }
};