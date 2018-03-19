class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string> > m;
        vector<vector<string> > res;
        // 排序以后放入map中
        for(auto it:strs)
        {
            string tem = it;
            sort(it.begin(), it.end());
            m[it].push_back(tem);
        }
        // 从map中取出
        for(auto it:m)
        {
            res.push_back(it.second);
        }
        return res;
    }
};