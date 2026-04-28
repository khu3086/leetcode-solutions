class Solution {
public:
    void perimeter(vector<vector<int>>& grid, vector<vector<bool>>& visited, int& peri, int row, int col, int i, int j){
        if(i<0||i>=row||j<0||j>=col||grid[i][j]==0||visited[i][j]) return;
        if(i==0||(i>0&&grid[i-1][j]==0)){
            peri++;
        }
        if(i==row-1||(i<row-1&&grid[i+1][j]==0)){
            peri++;
        }
        if(j==0||(j>0&&grid[i][j-1]==0)){
            peri++;
        }
        if(j==col-1||(j<col-1&&grid[i][j+1]==0)){
            peri++;
        }
        visited[i][j]=true;
        perimeter(grid, visited, peri, row, col, i+1, j);
        perimeter(grid, visited, peri, row, col, i-1, j);
        perimeter(grid, visited, peri, row, col, i, j+1);
        perimeter(grid, visited, peri, row, col, i, j-1);
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        int per=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    perimeter(grid, visited, per, row, col, i, j);
                }
            }
        }
        return per;
    }
};