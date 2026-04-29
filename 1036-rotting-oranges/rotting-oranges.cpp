class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        queue<pair<int, int>> q;

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==2) q.push({i, j});
            }
        }

        int curr = 0;

        while(!q.empty()){
            int k = q.size();
            bool spread = false;   // ✅ track if anything rotted

            for(int i=0;i<k;i++){
                auto idx = q.front();
                q.pop();

                int x = idx.first;
                int y = idx.second;

                if(x>0 && grid[x-1][y]==1){
                    grid[x-1][y]=2;
                    q.push({x-1, y});
                    spread = true;
                }
                if(y>0 && grid[x][y-1]==1){
                    grid[x][y-1]=2;
                    q.push({x, y-1});
                    spread = true;
                }
                if(x<row-1 && grid[x+1][y]==1){
                    grid[x+1][y]=2;
                    q.push({x+1, y});
                    spread = true;
                }
                if(y<col-1 && grid[x][y+1]==1){
                    grid[x][y+1]=2;
                    q.push({x, y+1});
                    spread = true;
                }
            }

            if(spread) curr++;   // ✅ increment only if spread happened
        }

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1) return -1;
            }
        }

        return curr;
    }
};