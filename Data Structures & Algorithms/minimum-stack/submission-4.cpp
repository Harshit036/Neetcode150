class MinStack {
private:
    stack<int> st;
    stack<int> minStack;
    int mini;
public:
    MinStack() {
        mini = INT_MAX;
    }
    
    void push(int val) {
        st.push(val);
        mini = min(mini, val);
        minStack.push(mini);
    }
    
    void pop() {
        st.pop();
        minStack.pop();
        if(minStack.empty()) mini = INT_MAX;
        else mini = minStack.top();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
