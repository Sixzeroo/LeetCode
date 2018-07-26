class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> s;
        vector<string> res;
        int minv = list1.size() + list2.size();
        for(int i = 0; i < list1.size(); i++)
            s.insert(make_pair(list1[i], i));
        for(int i = 0; i < list2.size(); i++)
        {
            auto tem = s.find(list2[i]);
            if(tem != s.end())
            {
                if(i + tem->second < minv)
                {
                    res.clear();
                    res.push_back(tem->first);
                    minv = i+tem->second;
                }
                else if(i + tem->second == minv)
                    res.push_back(tem->first);
            }
        }
        return res;
    }
};