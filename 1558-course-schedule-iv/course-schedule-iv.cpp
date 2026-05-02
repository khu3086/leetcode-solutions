class Solution {
public:
    vector<bool> checkIfPrerequisite(int num, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> reach(num, vector<bool>(num, false));
        vector<vector<int>> adj(num);
        vector<int> indegree(num, 0);
        for(auto pre: prerequisites){
            adj[pre[0]].push_back(pre[1]);
            indegree[pre[1]]++;
            reach[pre[0]][pre[1]]=true;
        }
        queue<int> q;
        for(int i=0;i<num;i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int top=q.front(); q.pop();
            for(auto nei: adj[top]){
                
             for(int i = 0; i < num; i++){
                    if(reach[i][top]){
                        reach[i][nei] = true;
                    }
                }
                indegree[nei]--;
                if(indegree[nei]==0) q.push(nei);
            }
        }
        vector<bool> ans;
        for(auto q: queries){
            ans.push_back(reach[q[0]][q[1]]);
        }
        return ans;
    }
};