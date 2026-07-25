class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        //multisrc bfs
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        vector<vector<int>> vis=grid;
        queue<pair<int, int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) {q.push({i, j}); count++;}
            }
        }
        if(count==0) return -1;
        else if(count==m*n) return -1;
        int maxval=INT_MIN;
        vector<vector<int>> dir={{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while(!q.empty()){
            int sz=q.size();
            while(sz){
                auto top=q.front(); q.pop();
                int i=top.first;
                int j=top.second;
                for(auto d: dir){
                    int x=i+d[0]; int y=j+d[1];
                    if(x>=0&&x<m&&y>=0&&y<n){
                        if(vis[x][y]==0){
                            vis[x][y]=vis[i][j]+1;
                            maxval=max(maxval, vis[x][y]);
                            q.push({x, y});
                        }
                    }
                }
                sz--;
            }
        }
        return maxval-1;
    }
};