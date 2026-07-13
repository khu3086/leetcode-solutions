class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dir={{0,1}, {0, -1}, {1, 0}, {-1, 0}};
        priority_queue<
    pair<int, pair<int,int>>,
    vector<pair<int, pair<int,int>>>,
    greater<pair<int, pair<int,int>>>
> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        pq.push({0, {0, 0}});
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            int currDist=top.first;
            int i=top.second.first;
            int j=top.second.second;
            if(visited[i][j]) continue;
            visited[i][j]=true;
            if(i==m-1&&j==n-1) return currDist;
            for(auto d: dir){
                int x=i+d[0]; int y=j+d[1];
                if(x>=0&&x<m&&y>=0&&y<n){
                    if(visited[x][y]) continue;
                    int nextDist=abs(grid[i][j]-grid[x][y]);
                    if(nextDist>dist[x][y]) continue;
                    dist[x][y]=max(currDist, nextDist);
                    pq.push({dist[x][y], {x, y}});
                }
            }
        }
        return dist[m-1][n-1];
    }
};