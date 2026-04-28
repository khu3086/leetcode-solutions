class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<bool>& path, vector<bool>& vis, int curr){
        vis[curr]=true;
        path[curr]=true;
        for(auto next: adj[curr]){
            if(!vis[next]) {
                if(dfs(adj, path, vis, next)) return true;
            }
            else if(path[next]) return true;
        }
        path[curr]=false;
        return false;
    }
    bool canFinish(int num, vector<vector<int>>& pre) {
        vector<vector<int>> adj(num);
        for(auto x: pre){
            adj[x[0]].push_back(x[1]);
        }
        vector<bool> path(num, false);
        vector<bool> vis(num, false);
        for(int i=0;i<num;i++){
            if(dfs(adj, path, vis, i)) return false;
        }
        return true;
    }
};