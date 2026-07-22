class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh=0;
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int, int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) fresh++;
                else if(grid[i][j]==2) q.push({i, j});
            }
        }
        if(fresh==0) return 0;
        vector<vector<int>> dir={{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int count=0;
        while(!q.empty()){
            int sz=q.size();
            count++;
            while(sz){
                auto top=q.front(); q.pop();
                int i=top.first;
                int j=top.second;
                for(auto d: dir){
                    int x=i+d[0]; int y=j+d[1];
                    if(x>=0&&x<m&&y>=0&&y<n){
                        if(grid[x][y]==1){
                            fresh--;
                            grid[x][y]=2;
                            q.push({x, y});
                        }
                    }
                }
                sz--;
            }
        }
        if(fresh==0)
        return count-1;
        return -1;
    }
};