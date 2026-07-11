class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prereq) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        for(auto p: prereq){
            adj[p[0]].push_back(p[1]);
            indegree[p[1]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<int> ans;
        vector<bool> vis(n, false);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            vis[node]=true;
            for(auto nxt: adj[node]){
                if(vis[nxt]) continue;
                indegree[nxt]--;
                if(indegree[nxt]==0) q.push(nxt);
            }
        }
        if(ans.size() != n)
    return {};
        reverse(ans.begin(), ans.end());
        return ans;
    }
};