class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<pair<int, int>>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int dist=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                adj[i].push_back({j, dist});
                adj[j].push_back({i, dist});
            }
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        int sum=0;
        vector<bool> vis(n, false);
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            int topdist=top.first;
            int topnode=top.second;
            if(!vis[topnode])
            {sum+=topdist;
            vis[topnode]=true;
            for(auto nei: adj[topnode]){
                int childdist=nei.second;
                int childnode=nei.first;
                if(!vis[childnode]){
                    pq.push({childdist, childnode});
                }
            }}
        }
        return sum;
    }
};