class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        minv = INT_MAX;
    }
    
    void push(int x) {
        st.push(x);
        minv = min(minv, x);
        min_st.push(minv);
    }
    
    void pop() {
        st.pop();
        min_st.pop();
        if (min_st.empty())
            minv = INT_MAX;
        else
            minv = min_st.top();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_st.top();
    }

private:
    stack<int> st, min_st;
    int minv;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */