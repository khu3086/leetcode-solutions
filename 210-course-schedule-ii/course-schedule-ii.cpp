class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        vector<int> ans;
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<pre.size();i++){
            adj[pre[i][1]].push_back(pre[i][0]);
            indegree[pre[i][0]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int top=q.front(); q.pop();
            ans.push_back(top);
            for(auto x: adj[top]){
                indegree[x]--;
                if(indegree[x]==0) q.push(x);
            }
        }
        if(ans.size()==numCourses) return ans;
        return {};
    }
};