class MinStack {
public:
    int mini = INT_MAX;
    stack<pair<int,int>> st;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
           
            st.push({val,val});
             mini = val;
        }else{
            mini = min(val,mini);
            st.push({val,mini});
        }
    }
    
    void pop() {
        
        st.pop();
        if(!st.empty()){
            mini = st.top().second;
        }
        
        
    }
    
    int top() {
        return st.top().first;
        
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your miniStack object will be instantiated and called as such:
 * miniStack* obj = new miniStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getmini();
 */