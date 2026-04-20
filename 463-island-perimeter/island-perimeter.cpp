class Solution {
public:
    void dfs(vector<vector<int>>& grid, int& edge, vector<vector<bool>>& visited, int row, int col, int i, int j){
        if(i<0||i>=row||j<0||j>=col||visited[i][j]) return;
        if(grid[i][j]==0) return;
        visited[i][j]=true;
        if(i>0&&grid[i-1][j]) //1 cell up island hai
        dfs(grid, edge, visited, row, col, i-1, j);
        else edge++;

        if(j>0&&grid[i][j-1]) //1 cell right island hai
        dfs(grid, edge, visited, row, col, i, j-1);
        else edge++;

        if(i<row-1&&grid[i+1][j]) //1 cell down island hai
        dfs(grid, edge, visited, row, col, i+1, j);
        else edge++;

        if(j<col-1&&grid[i][j+1]) //1 cell left island hai
        dfs(grid, edge, visited, row, col, i, j+1);
        else edge++;

    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        int edge=0;
        int i=0, j=0;
        for(i=0;i<row;i++){
            for(j=0;j<col;j++){
                if(grid[i][j]==1)dfs(grid, edge, visited, row, col, i, j);
            }
        }
        return edge;
    }
};