class MinStack {
stack<int> st, minst;
int mininp = INT_MAX;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        mininp = min(val, mininp);
        minst.push(mininp);
    }
    
    void pop() {
        st.pop();
        minst.pop();
        if (minst.size() > 0) mininp = minst.top();
        else mininp = INT_MAX;
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minst.top();
    }
};
