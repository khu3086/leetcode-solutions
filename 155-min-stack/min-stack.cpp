class MinStack {
public:
    stack<int> minstack;
    stack<int> regstack;
    MinStack() {
        
    }
    
    void push(int val) {
        if(minstack.empty() || val <= minstack.top()) minstack.push(val);
        regstack.push(val);
    }
    
    void pop() {
        if(minstack.top()==regstack.top()) minstack.pop();
        regstack.pop();
    }
    
    int top() {
        return regstack.top();
    }
    
    int getMin() {
        return minstack.top();
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