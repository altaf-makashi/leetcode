class MinStack {
public:
    stack<pair<int,int>>st;
    int min_value;
    MinStack() {
        
    }
    
    void push(int value) {
        if(st.empty()){
            st.push({value,value});
            min_value=value;
            return ;
        }
        min_value=st.top().second;
        min_value=min(min_value,value);
        st.push({value,min_value});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        auto it=st.top();
        return it.first;
    }
    
    int getMin() {
        auto it=st.top();
        return it.second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */