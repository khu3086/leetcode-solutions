class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prereq) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        for(auto pre: prereq){
            adj[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        int count=0;
        while(!q.empty()){
            int top=q.front();
            q.pop();
            count++;
            for(auto neigh: adj[top]){
                indegree[neigh]--;
                if(indegree[neigh]==0) {q.push(neigh);}
            }
        }
        return n==count;
    }
};