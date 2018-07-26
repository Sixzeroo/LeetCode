class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> s;
        int len = nums.size();
        for(int i : nums)
        {
            if(s.find(i) != s.end())
                s[i]++;
            else
                s.insert(make_pair(i, 1));
            if(s[i] > len / 2)
                return i;
        }
        return -1;
    }
};