class Solution {
public:
    unordered_map<string, vector<string>> dict;
    
    // dp结合递归实现
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if(dict.count(s)) return dict[s];
        int len = s.size();
        vector<string> res;
        for(int i = 1; i <= len; i++)
        {
            string word = s.substr(0, i), remain = s.substr(i);
            if(find(wordDict.begin(), wordDict.end(), word) != wordDict.end())
            {
                if(remain == "") res.push_back(word);
                else for(auto it : wordBreak(remain, wordDict)) res.push_back(word + " " + it);
            }
        }
        dict[s] = res;
        return res;
    }
};