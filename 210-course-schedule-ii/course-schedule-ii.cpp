class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prereq) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        queue<int> q;
        for(auto p: prereq){
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        vector<int> ans;
        vector<bool> vis(n, false);
        for(int i=0;i<n;i++){
            if(indegree[i]==0) {q.push(i); vis[i]=true;}
        }
        while(!q.empty()){
            int top=q.front();
            q.pop();
            ans.push_back(top);
            for(auto nxt: adj[top]){
                indegree[nxt]--;
                if(indegree[nxt]==0&&!vis[nxt]) q.push(nxt);
            }
        }
        //reverse(ans.begin(), ans.end());
        if(ans.size()==n) return ans;
        return {};
    }
};