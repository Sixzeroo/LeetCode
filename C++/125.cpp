class Solution {
public:
    string transform(string s)
    {
        string res;
        for(auto i : s)
        {
            if(i >= 'A' && i <= 'Z') res.push_back(i + 32);
            if((i >= 'a' && i <= 'z' ) || (i >= '0' && i <= '9')) res.push_back(i);
        }
        return res;
    }
    
    bool isPalindrome(string s) {
        string new_s = transform(s);
        int len = new_s.size();
        if(len == 0) return true;
        for(int i = 0; i <= len / 2 + 1; i++)
            if(new_s[i] != new_s[len - i - 1]) return false;
        return true;
            
    }
};