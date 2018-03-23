class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int lena = a.size(), lenb = b.size();
        int cap=0, i=lena-1, j=lenb-1;
        while(i>=0 || j>=0)
        {
            char ca = i>=0?a[i]:'0';
            char cb = j>=0?b[j]:'0';
            cout<<ca<<" "<<cb<<endl;
            int tem = ca + cb - 2*'0' + cap;
            res.push_back('0'+tem%2);
            cap = tem/2;
            i--, j--;
        }
        if(cap) res.push_back('1');
        //if(res.back() == '0') res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};