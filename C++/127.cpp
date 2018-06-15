class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
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
        return res.size() == 0 ? 0 : res[0].size();
    }
};