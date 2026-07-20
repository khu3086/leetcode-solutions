class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        for(auto t: times){
            int u=t[0];
            int v=t[1];
            int dist=t[2];
            adj[u].push_back({v, dist});
        }
        vector<int> distance(n+1, INT_MAX);
        distance[k]=0;
        distance[0]=0;
        int sum=0;
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            int node=top.second;
            int dist=top.first;
            if(dist > distance[node]) continue;
            for(auto nei: adj[node]){
                int neinode=nei.first;
                int neidist=nei.second;
                
                if(neidist+dist<distance[neinode]){
                    distance[neinode]=neidist+dist;
                    pq.push({distance[neinode], neinode});
                }
            }
        }
        int ans=0;
        for(int i=0;i<=n;i++){
            if(distance[i]==INT_MAX) return -1;
            ans=max(ans, distance[i]);
        }
        return ans;
    }
};