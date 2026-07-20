class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prereq) {
        vector<vector<int>> adj(n);
        vector<int> indeg(n, 0);
        vector<int> ans;
        queue<int> q;
        for(auto p: prereq){
            adj[p[1]].push_back(p[0]);
            indeg[p[0]]++;
        }
        for(int i=0;i<n;i++){
            if(indeg[i]==0) q.push(i);
        }
        while(!q.empty()){
            int top=q.front();
            q.pop();
            ans.push_back(top);
            for(auto nei: adj[top]){
                indeg[nei]--;
                if(indeg[nei]==0) q.push(nei);
            }
        }
        if(ans.size()!=n) return {};
        return ans;
    }
};