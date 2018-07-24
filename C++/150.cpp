class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string s : tokens) {
            if(s == "+" || s == "-" || s == "*" || s == "/")
            {
                int s_op = st.top();
                st.pop();
                int f_op = st.top();
                st.pop();
                int tem;
                switch(s[0]) {
                    case '+':
                        tem = f_op + s_op;
                        break;
                    case '-':
                        tem = f_op - s_op;
                        break;
                    case '*':
                        tem = f_op * s_op;
                        break;
                    case '/':
                        tem = f_op / s_op;
                        break;
                }
                st.push(tem);
            } else {
                int s_int = str2int(s);
                st.push(s_int);
            }
        }
        int res = st.top();
        return res;
    }
private:
    int str2int(string s) {
        int res = 0, len = s.size();
        bool neg_tag = false;
        int i = 0;
        if(s[0] == '-') 
        {
            neg_tag = true;
            i++;
        }
        for(; i < len; i++)
            res = res * 10 + s[i] - '0';
        return neg_tag ? -res : res;
    }
};