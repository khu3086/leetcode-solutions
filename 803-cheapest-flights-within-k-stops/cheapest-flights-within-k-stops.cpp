class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        queue<pair<int, int>> pq;
        pq.push({0, src});
        vector<int> distance(n, INT_MAX);
        int hop=0;
        distance[src]=0;
        for(auto f: flights){
            int u=f[0];
            int v=f[1];
            int price=f[2];
            adj[u].push_back({v, price});
        }
        while(!pq.empty()&&hop<=k){
            hop++;
            int sz=pq.size();
            vector<int> temp = distance; 
            while (sz--) {
    auto [dist, node] = pq.front();
    pq.pop();

    if (dist > distance[node])
        continue;

    for (auto [currnode, currdist] : adj[node]) {
        if (dist + currdist < temp[currnode]) {
            temp[currnode] = dist + currdist;
            pq.push({dist + currdist, currnode});
        }
    }
}
            distance=temp;
        }
        if(distance[dst]==INT_MAX) return -1;
        return distance[dst];
    }
};