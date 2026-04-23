class Solution {
private:
    bool dfs(vector<vector<int>>& adj, vector<bool>& path, vector<bool>& vis, int curr){
        vis[curr]=true;
        path[curr]=true;
        for(int next: adj[curr]){
            if(!vis[next]){
                if(dfs(adj, path, vis, next)) return true;
            }
            else if(path[next]) return true;
        }
        path[curr]=false;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto pre: prerequisites) adj[pre[1]].push_back(pre[0]);
        vector<bool> vis(numCourses, false);
        vector<bool> path(numCourses, false);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(adj, path, vis, i)) return false;
            }
        }
        return true;
    }
};