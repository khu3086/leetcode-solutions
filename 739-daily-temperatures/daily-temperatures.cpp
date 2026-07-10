class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> stk;
        vector<int> ans(temperatures.size(), 0);
        for(int i=0;i<temperatures.size();i++){
            if(stk.empty()){
                stk.push({temperatures[i], i});
                continue;
            }
            while(!stk.empty()&&stk.top().first<temperatures[i]){
                int temp=stk.top().first;
                int idx=stk.top().second;
                ans[idx]=i-idx;
                stk.pop();
            }
            stk.push({temperatures[i], i});
        }
        return ans;
    }
};