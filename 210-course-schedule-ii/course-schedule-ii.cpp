class Solution {
public:
    vector<int> findOrder(int num, vector<vector<int>>& pre) {
        unordered_map<int, vector<int>> map;
        vector<int> indegree(num, 0);
        for(auto x: pre){
            map[x[1]].push_back(x[0]);
            indegree[x[0]]++;
        }
        queue<int> q;
        for(int i=0;i<num;i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int top=q.front();
            q.pop();
            ans.push_back(top);
            for(auto x: map[top]){
                indegree[x]--;
                if(indegree[x]==0) q.push(x);
            }
        }
        if(ans.size()<num) return {};
        return ans;
    }
};