class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(int i : nums)
        {
            if(s.find(i) != s.end())
                return true;
            else
                s.insert(i);
        }
        return false;
    }
};