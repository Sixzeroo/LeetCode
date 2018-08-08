class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mapST, mapTS;
        
        if (s.size() != t.size()) return false;
        
        for (int i = 0; i < s.size(); i++) {    
            if (mapST[s[i]] == t[i]) continue;
            if (mapST[s[i]] || mapTS[t[i]]) return false;
            
            mapST[s[i]] = t[i];
            mapTS[t[i]] = s[i];
        }
        
        return true;
    }
};