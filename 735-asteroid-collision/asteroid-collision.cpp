class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<pair<int, int>> stk;
        int n=asteroids.size();
        for(int i=0;i<n;i++){
            int mag=asteroids[i];
            int idx=i;
            if(stk.empty()){
                stk.push({mag, idx});
                continue;
            }
            bool canCollide=false;
            int stkmag=stk.top().first;
            int stkidx=stk.top().second;

            if(stkmag<0&&mag<0){
                stk.push({mag, idx});
            }
            else if(stkmag>0&&mag<0){
                canCollide=true;
                if(stkmag>abs(mag)) continue;
                else if(stkmag<abs(mag)){
                    while(!stk.empty()&&stk.top().first>0&&stk.top().first<abs(mag)) stk.pop();
                }
                if(stk.empty()) stk.push({mag, idx});
                else if(stk.top().first<0) stk.push({mag, idx});
                else if(stk.top().first==abs(mag)) stk.pop();
                else continue;
            }
            else if(stkmag>0&&mag>0) stk.push({mag, idx});
            else{
                //stkmag<0&&mag>0 
                stk.push({mag, idx});
            }
        }
        vector<int> ans;
        while(!stk.empty()){
            ans.push_back(stk.top().first);
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};