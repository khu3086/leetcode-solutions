class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int fresh=0;
        int row=grid.size();
        int col=grid[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==2) q.push({i, j});
                if(grid[i][j]==1) fresh++;
            }
        }
        if(fresh==0) return 0;
        if(q.empty()) return -1;
        int curr=0;
        while(!q.empty()){
            bool spread=false;
            int k=q.size();
            for(int i=0;i<k;i++)
            {auto top=q.front();
            q.pop();
            
            int x=top.first;
            int y=top.second;
            if(x>0&&grid[x-1][y]==1){
                spread=true;
                grid[x-1][y]=2;
                q.push({x-1, y});
                fresh--;
            }
            if(y>0&&grid[x][y-1]==1){
                spread=true;
                grid[x][y-1]=2;
                q.push({x, y-1});
                fresh--;
            }
            if(x<row-1&&grid[x+1][y]==1){
                spread=true;
                grid[x+1][y]=2;
                q.push({x+1, y});
                fresh--;
            }
            if(y<col-1&&grid[x][y+1]==1){
                spread=true;
                grid[x][y+1]=2;
                q.push({x, y+1});
                fresh--;
            }}
            if(spread) curr++;
        }
        if(fresh) return -1;
        return curr;
    }
};