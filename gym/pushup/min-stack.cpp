class MinStack {
private:
    stack<int> st;
    int minimum;
public:
    /** initialize your data structure here. */
    MinStack() {
        minimum = INT_MAX;
    }

    void push(int x) {
        if (minimum >= x){
            st.push(minimum);
            minimum = x;
        }
        st.push(x);
    }

    void pop() {
        if (minimum == st.top()){
            st.pop();
            minimum = st.top();
            st.pop();
        }
        else
            st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minimum;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
