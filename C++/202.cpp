class Solution {
public:
    int getNum(int n) {
        int res = 0;
        while(n)
        {
            res += pow((n % 10), 2);
            n /= 10;
        }
        return res;
    }
    
    bool isHappy(int n) {
        int tem = n;
        unordered_set<int> s;
        while(tem != 1)
        {
            tem = getNum(tem);
            if(s.find(tem) != s.end()) return false;
            s.insert(tem);
        }
        return true;
    }
};