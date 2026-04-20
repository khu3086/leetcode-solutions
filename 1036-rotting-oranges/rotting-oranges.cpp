class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int row=grid.size();
        int col=grid[0].size();
        int minmax=0;

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==2){
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()){
            int size = q.size();
            minmax++;
            while(size--){
                auto x= q.front();
                int ii=x.first;
                int jj=x.second;
                q.pop();

                if(ii>0&&grid[ii-1][jj]==1){
                    q.push({ii-1, jj});
                    grid[ii-1][jj]=2;
                }
                if(jj>0&&grid[ii][jj-1]==1){
                    q.push({ii, jj-1});
                    grid[ii][jj-1]=2;
                }
                if(ii < row-1 && grid[ii+1][jj]==1){
                    q.push({ii+1, jj});
                    grid[ii+1][jj]=2;
                }
                if(jj < col-1 && grid[ii][jj+1]==1){
                    q.push({ii, jj+1});
                    grid[ii][jj+1]=2;
                }
            }
        }

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1) return -1;
            }
        }

        return minmax==0 ? 0 : minmax-1;
    }
};