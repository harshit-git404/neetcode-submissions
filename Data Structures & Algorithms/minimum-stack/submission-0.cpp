class MinStack {
public:
    stack<int> st;
    stack<int> minVal;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        val=min(val,(minVal.empty()?val:minVal.top()));
        minVal.push(val);
    }
    
    void pop() {
        st.pop();
        minVal.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minVal.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */