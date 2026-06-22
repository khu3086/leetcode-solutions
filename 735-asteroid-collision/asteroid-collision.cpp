class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;
        for(auto incom: asteroids){
            bool flag=false;
            while(!stk.empty()&&stk.top()>0&&incom<0){
                if(abs(stk.top())<abs(incom)){
                    stk.pop();
                }
                else if(abs(stk.top())==abs(incom)){
                    stk.pop();
                    flag=true;
                    break;
                }
                else if(abs(stk.top())>abs(incom)){
                    flag=true;
                    break;
                }
            }
            if(!flag) stk.push(incom);
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