/*
* Solution 1 : DFS
* time out
*/ 
class Solution {
public:
    void backtracking(string now_s, string target, unordered_map<string, bool> &words, vector<vector<string> > &res, vector<string> local)
    {
        if(now_s == target)
        {
            local.push_back(target);
            // 取最小长度的结果
            while(!res.empty() && res[res.size() - 1].size() > local.size())
                res.pop_back();
            if(res.empty() || res[res.size() - 1].size() == local.size())
                res.push_back(local);
            return;
        }
        int len = now_s.size();
        local.push_back(now_s);
        for(int i = 0; i < len; i++)
        {
            for(char tem = 'a'; tem <= 'z'; tem++)
            {
                string tem_s = now_s;
                tem_s[i] = tem;
                auto ret = words.find(tem_s);
                // 不在给定的路径里面 或者 之前被使用过
                if(ret == words.end() || ret->second == false)
                    continue;
                ret->second = false;
                backtracking(tem_s, target, words, res, local);
                ret->second = true;
            }
        }
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string> > res;
        vector<string> local;
        unordered_map<string, bool> unused;
        for(auto it : wordList)
            unused.insert(make_pair(it, true));
        backtracking(beginWord, endWord, unused, res, local);
        return res;
    }
};

/*
* Solution : BFS
* AC
*/
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // 所有单词的集合
        unordered_set<string> words;
        for(auto it : wordList) words.insert(it);
        
        vector<vector<string> > res;
        // 使用队列进行BFS
        queue<vector<string> > paths;
        paths.push({beginWord});
        int level = 1;
        int min_level = INT_MAX;
        // 在本层中使用过的单词
        vector<string> used;
        
        while(!paths.empty())
        {
            vector<string> path = paths.front();
            paths.pop();
            // 遍历到新的层上
            if(path.size() > level)
            {
                // 对上一层使用过的单词进行清理
                for(string item : used) words.erase(item);
                used.clear();
                if(path.size() > min_level)
                    break;
                else
                    level = path.size();
            }
            // 根据最后一个单词向后扩展
            string last = path.back();
            for(int i = 0; i < last.size(); i++)
            {
                string new_s = last;
                for(char j = 'a'; j <= 'z'; j++)
                {
                    new_s[i] = j;
                    // 是路径中的单词
                    if(words.find(new_s) != words.end())
                    {
                        vector<string> new_path = path;
                        new_path.push_back(new_s);
                        used.push_back(new_s);
                        if(new_s == endWord)
                        {
                            min_level = level;
                            res.push_back(new_path);
                        }
                        else
                            paths.push(new_path);
                    }
                }
            }
        }
        return res;
    }
};