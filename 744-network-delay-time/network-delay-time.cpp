class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto e: times){
            adj[e[0]].push_back({e[1], e[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        vector<int> dist(n+1, INT_MAX);
        dist[0]=0;
        dist[k]=0;
        while(!pq.empty()){
            auto [d, u]=pq.top();
            pq.pop();
            if(d>dist[u]) continue;
            for(auto& [v, wt]: adj[u]){
                if(d+wt<dist[v]){
                    dist[v]=d+wt;
                    pq.push({d+wt, v});
                }
            }
        }
        int ans=0;
        for(auto d: dist){
            if(d==INT_MAX) return -1;
            ans=max(ans, d);
        }
        return ans;

    }
};