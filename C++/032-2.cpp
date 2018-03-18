class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int len = s.length();
        int res = 0;
        st.push(-1);
        for(int i=0; i<len; i++)
        {
            if(s[i] == '(')
                st.push(i);
            else
            {
                st.pop();
                // 栈为空的时候表示新的串匹配开始
                if(st.empty())
                    st.push(i);
                else
                {
                    res = max(res, i-st.top());
                }
            }
        }
        return res;
    }
};