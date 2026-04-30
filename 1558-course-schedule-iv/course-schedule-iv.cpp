class Solution {
public:
    vector<bool> checkIfPrerequisite(int num, vector<vector<int>>& pre, vector<vector<int>>& queries) {
        vector<vector<bool>> reach(num, vector<bool>(num, false));
        vector<vector<int>> adj(num);
        vector<int> indegree(num, 0);
        queue<int> q;
        for(int i=0;i<pre.size();i++){
            int src=pre[i][0];
            int dest=pre[i][1];
            adj[src].push_back(dest);
            indegree[dest]++;
            reach[src][dest]=true;
        }
        for(int i=0;i<num;i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int top=q.front();
            q.pop();
            for(auto src: adj[top]){
                indegree[src]--;
                if(indegree[src]==0) q.push(src);
                for(int i=0;i<num;i++){
                    reach[i][src]=reach[i][top]||reach[i][src];
                }
            }
        }
        vector<bool> ans;
        for(auto x: queries){
            ans.push_back(reach[x[0]][x[1]]);
        }
        return ans;
    }
};