class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        //create adj list;
        int n=points.size();
        //node-> idx number, and dist)
        vector<vector<pair<int, int>>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int dist=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                adj[i].push_back({j, dist});
                adj[j].push_back({i, dist});
            }
        }
        //prims algo-> min heap pf {dist, dest}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> inMST(n, false);
        pq.push({0, 0});
        int sum=0;
        //int lastnode=0;
        while(!pq.empty()){
            auto [dist, node]=pq.top();
            //lastnode=node;
            pq.pop();
            if(inMST[node]) continue;
            inMST[node]=true;
            sum+=dist;
            for(auto nei: adj[node]){
                int child=nei.first;
                int childdist=nei.second;
                if(inMST[(child)]){
                    continue;
                }
                pq.push({childdist, child});
            }
        }
        return sum;
    }
};