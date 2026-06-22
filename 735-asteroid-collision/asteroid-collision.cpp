class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int> stk;
        for(int i=0;i<ast.size();i++){
            int incom=ast[i];
            int flag=true;
            while(!stk.empty()&&stk.top() > 0 && incom < 0){
                if(abs(stk.top())<abs(incom)){
                    stk.pop();
                }
                else if(abs(stk.top())==abs(incom)){
                    stk.pop();
                    flag=false;
                    break;
                }
                else{
                    flag = false; // incoming destroyed
                    break;
                }
            }
            if(flag)
            stk.push(incom);
        }
        vector<int> ans;
        while(!stk.empty()){
            ans.push_back(stk.top());
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};