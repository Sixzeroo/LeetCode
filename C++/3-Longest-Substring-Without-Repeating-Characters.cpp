class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int a[256];
        memset(a,0,sizeof(a));
        int ans=0,num=0,start=0;
        for(int i=1;i<=s.size();i++)
        {
            start=start>a[s[i-1]]?start:a[s[i-1]];
            num=i-start;
            ans=ans>num?ans:num;
            a[s[i-1]]=i;
        }
        ans=ans>num?ans:num;
        return ans;
    }
};