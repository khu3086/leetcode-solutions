class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(auto x: s){
            if(x=='('||x=='['||x=='{') {stk.push(x); continue;}
            if(stk.empty()) return false;
            if(x==')'){
                if(stk.top()!='(') return false;
                stk.pop();
            }
            if(x==']'){
                if(stk.top()!='[') return false;
                stk.pop();
            }
            if(x=='}'){
                if(stk.top()!='{') return false;
                stk.pop();
            }
        }
        if(stk.size()==0) return true;
        return false;
    }
};