class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0]=0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});
        vector<vector<int>> dir={{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while(!pq.empty()){
            auto top=pq.top(); pq.pop();
            int distance=top.first;
            int i=top.second.first;
            int j=top.second.second;
            if(i==m-1&&j==n-1) return distance;
            for(auto d: dir){
                int x=d[0]+i;
                int y=d[1]+j;
                if(x>=0&&x<m&&y>=0&&y<n){
                    int newEffort = max(distance, abs(heights[x][y] - heights[i][j]));
                    if(newEffort>=dist[x][y]) continue;
                    dist[x][y]=newEffort;
                    pq.push({dist[x][y], {x, y}});
                }
            }
        }
        return -1;
    }
};