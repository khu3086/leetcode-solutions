class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto f: flights){
            adj[f[0]].push_back({f[1], f[2]});
        }
        vector<int> dist(n, INT_MAX);
        dist[src]=0;
        for(int i=0;i<=k;i++){
            vector<int> temp=dist;
            for(auto f: flights){
                int u=f[0], v=f[1], price=f[2];
                if(dist[u]!=INT_MAX)
                temp[v]=min(temp[v], dist[u]+price);
            }
            dist=temp;
        }
        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];
    }
};