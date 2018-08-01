class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> s;
        for(char i : J)
            s.insert(i);
        int res = 0;
        for(char i : S)
            if(s.find(i) != s.end()) res++;
        return res;
    }
};