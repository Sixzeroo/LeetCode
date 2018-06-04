class Solution {
public:
    string minWindow(string s, string t) {
        int len1 = s.size(), len2 = t.size();
        string res = "";
        if(len2 > len1) return "";
        // 两个字符串的计数数组
        vector<int> ht(256, 0), ht2(256, 0);
        for(int i = 0; i < len2; i++)
            ht[t[i]]++;
        // 双指针记录滑动窗口位置，minLen 赋比可能情况都大的初值
        int left = 0, right = 0, count = 0, minLen = len1 + 1;
        for(right = 0; right < len1; right++)
        {
            if(ht[s[right]] == 0) continue;
            ht2[s[right]] ++;
            // 在t中的数
            if(ht2[s[right]] <= ht[s[right]])
                count ++;
            // 都在窗口内的时候滑动左边的指针
            while(count == len2)
            {
                // 更新最值
                if(right - left + 1 < minLen)
                {
                    minLen = right - left + 1;
                    res = s.substr(left, minLen);
                }
                //最左边的值在搜寻范围内
                if(ht[s[left]] != 0) 
                {
                    ht2[s[left]] --;
                    if(ht2[s[left]] < ht[s[left]]) count--;
                }
                left ++;   
            }
        }
        return res;
    }
};