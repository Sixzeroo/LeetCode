class Solution {
public:
    // 转化为数组进行比较
    int str2int(string s)
    {
        int len = s.size(), res = 0;
        for(int i = 0; i < len; i++)
            res = res * 10 + s[i] - '0';
        return res;
    }
    
    vector<int> solute(string v)
    {
        int len = v.size();
        vector<int> res;
        for(int i = 0; i < len; i++)
        {
            if(v[i] != '.')
            {
                int j = i+1;
                while(j < len && v[j] != '.') j++;
                res.push_back(str2int(v.substr(i, j - i)));
                i = j - 1;
            }
        }
        return res;
    }
    
    int compareVersion(string version1, string version2) {
        vector<int> v1 = solute(version1), v2 = solute(version2);
        int len1 = v1.size(), len2 = v2.size();
        int len = max(len1, len2);
        for(int i = 0; i < len; i++)
        {
            int tem1 = i < len1 ? v1[i] : 0;
            int tem2 = i < len2 ? v2[i] : 0;
            if(tem1 > tem2) return 1;
            else if(tem1 < tem2) return -1;
        }
        return 0;
    }
};