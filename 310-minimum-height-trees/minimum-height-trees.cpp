class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> indeg(n, 0);
        if(n==1) return {0};
        for(auto e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            indeg[e[0]]++;
            indeg[e[1]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indeg[i]==1) q.push(i);
        }
        int remaining=n;
        while(remaining>2){
            remaining-=q.size();
            int sz=q.size();
            while(sz){
                int top=q.front(); q.pop();
                indeg[top]--;
                for(auto nei: adj[top]){
                    indeg[nei]--;
                    if(indeg[nei]==1) q.push(nei);
                }
                sz--;
            }
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};