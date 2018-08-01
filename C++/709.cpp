class Solution {
public:
    string toLowerCase(string str) {
        for(int i = 0; i < str.size(); i++)
            str[i] = str[i] < 91 && str[i] > 64 ? str[i] + 32 : str[i];
        return str;
    }
};