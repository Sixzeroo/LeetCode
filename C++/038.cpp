class Solution {
public:
    string countAndSay(int n) {
        // 模拟法
        string a = "1";
        for(int i=2;i<=n;++i)
        {
            string b = "";
            for(int j=0;j<a.length();)
            {
                int num = 1;
                while(j+num < a.length() && a[j+num] == a[j])
                    num++;
                b.push_back(to_string(num)[0]);
                b.push_back(a[j]);
                j = j+num;
            }
            a = b;
        }
        return a;
    }
};