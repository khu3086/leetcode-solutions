class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(auto c: s){
            if(c==')'){
                if(stk.size()&&stk.top()=='(') stk.pop();
                else stk.push(c);
            }
            else if(c==']'){
                if(stk.size()&&stk.top()=='[') stk.pop();
                else stk.push(c);
            }
            else if(c=='}'){
                if(stk.size()&&stk.top()=='{') stk.pop();
                else stk.push(c);
            }
            else stk.push(c);
        }
        if(stk.size()) return false;
        return true;
    }
};