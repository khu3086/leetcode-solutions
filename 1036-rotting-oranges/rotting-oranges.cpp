class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;

        // collect all sources
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 2) {
                    q.push({i, j});
                }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        int minutes = 0;

        // single BFS
        while(!q.empty() && fresh > 0){
            int size = q.size();
            minutes++;

            while(size--){
                auto top = q.front();
                q.pop();
                int i = top.first;
                int j = top.second;

                if(i>0 && grid[i-1][j]==1){
                    grid[i-1][j]=2;
                    fresh--;
                    q.push({i-1, j});
                }
                if(j>0 && grid[i][j-1]==1){
                    grid[i][j-1]=2;
                    fresh--;
                    q.push({i, j-1});
                }
                if(i<row-1 && grid[i+1][j]==1){
                    grid[i+1][j]=2;
                    fresh--;
                    q.push({i+1, j});
                }
                if(j<col-1 && grid[i][j+1]==1){
                    grid[i][j+1]=2;
                    fresh--;
                    q.push({i, j+1});
                }
            }
        }

        return (fresh == 0) ? minutes : -1;
    }
};