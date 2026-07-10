class MinStack {
public:
    stack<int> stk;
    stack<int> minstk;
    MinStack() {
        
    }
    
    void push(int value) {
        
        if(!minstk.empty()&&minstk.top()>=value){
            minstk.push(value);
        }
        else if(minstk.empty()) minstk.push(value);
        stk.push(value);
    }
    
    void pop() {
        if(!minstk.empty()&&!stk.empty()&&minstk.top()==stk.top()){
            minstk.pop();
        }
        if(!stk.empty())stk.pop();
    }
    
    int top() {
        return stk.top();

    }
    
    int getMin() {
        return minstk.top();
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