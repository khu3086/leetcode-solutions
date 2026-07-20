class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prereq, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        vector<vector<bool>> table(n, vector<bool>(n, false));
        vector<int> indegree(n, 0);
        for(auto p: prereq){
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
            table[p[1]][p[0]]=true;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i); 
        }
        while(!q.empty()){
            int top=q.front(); q.pop();
            //if curr node is prereq of something, it will be prereq of their nei
            for(auto nei: adj[top]){
                for(int i=0;i<n;i++){
                    if(table[i][top]) table[i][nei]=true;
                }
                indegree[nei]--;
                if(indegree[nei]==0) q.push(nei);
            }
        }
        vector<bool> ans;
        for(auto q: queries){
            ans.push_back(table[q[1]][q[0]]);
        }
        return ans;
    }
};